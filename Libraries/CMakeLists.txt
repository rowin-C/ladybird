add_subdirectory(LibCompress)
add_subdirectory(LibCrypto)
add_subdirectory(LibDiff)
add_subdirectory(LibDNS)
add_subdirectory(LibGC)
add_subdirectory(LibIPC)
add_subdirectory(LibJS)
add_subdirectory(LibRegex)
add_subdirectory(LibRIFF)
add_subdirectory(LibSyntax)
add_subdirectory(LibTest)
add_subdirectory(LibTextCodec)
add_subdirectory(LibThreading)
add_subdirectory(LibTLS)
add_subdirectory(LibUnicode)
add_subdirectory(LibURL)
add_subdirectory(LibXML)

# FIXME: Increase support for building targets on Windows
if (WIN32 AND ENABLE_WINDOWS_CI)
    return()
endif()

add_subdirectory(LibHTTP)
add_subdirectory(LibLine)
add_subdirectory(LibRequests)
add_subdirectory(LibWasm)
add_subdirectory(LibWebSocket)

if (ENABLE_GUI_TARGETS)
    add_subdirectory(LibDevTools)
    add_subdirectory(LibGfx)
    add_subdirectory(LibImageDecoderClient)
    add_subdirectory(LibMedia)
    add_subdirectory(LibWeb)
    add_subdirectory(LibWebView)
endif()
