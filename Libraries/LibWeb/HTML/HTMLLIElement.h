/*
 * Copyright (c) 2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/GenericShorthands.h>
#include <LibWeb/HTML/HTMLElement.h>
#include <LibWeb/HTML/HTMLOListElement.h>
#include <LibWeb/HTML/HTMLUListElement.h>
#include <LibWeb/WebIDL/Types.h>

namespace Web::HTML {

class HTMLLIElement final : public HTMLElement {
    WEB_PLATFORM_OBJECT(HTMLLIElement, HTMLElement);
    GC_DECLARE_ALLOCATOR(HTMLLIElement);

public:
    virtual ~HTMLLIElement() override;

    // https://www.w3.org/TR/html-aria/#el-li
    virtual Optional<ARIA::Role> default_role() const override
    {
        for (auto ancestor = parent_element(); ancestor; ancestor = ancestor->parent_element()) {
            if (ancestor->role_or_default() == ARIA::Role::list)
                return ARIA::Role::listitem;
        }
        // https://w3c.github.io/core-aam/#roleMappingComputedRole
        // When an element has a role but is not contained in the required context (for example, an orphaned listitem
        // without the required accessible parent of role list), User Agents MUST ignore the role token, and return the
        // computedrole as if the ignored role token had not been included.
        return ARIA::Role::none;
    }

    WebIDL::Long value();
    void set_value(WebIDL::Long value)
    {
        MUST(set_attribute(AttributeNames::value, String::number(value)));
    }

    virtual bool is_html_li_element() const override { return true; }

private:
    HTMLLIElement(DOM::Document&, DOM::QualifiedName);

    virtual void initialize(JS::Realm&) override;
    virtual void attribute_changed(FlyString const& local_name, Optional<String> const& old_value, Optional<String> const& value, Optional<FlyString> const& namespace_) override;

    virtual bool is_presentational_hint(FlyString const&) const override;
    virtual void apply_presentational_hints(GC::Ref<CSS::CascadedProperties>) const override;
};

}

namespace Web::DOM {

template<>
inline bool Node::fast_is<Web::HTML::HTMLLIElement>() const { return is_html_li_element(); }

}
