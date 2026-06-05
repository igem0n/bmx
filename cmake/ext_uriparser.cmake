if(uriparser_link_lib)
    return()
endif()


if(BMX_BUILD_URIPARSER_SOURCE)
    include(FetchContent)

    set(URIPARSER_BUILD_DOCS OFF CACHE INTERNAL "")
    set(URIPARSER_BUILD_TESTS OFF CACHE INTERNAL "")
    set(URIPARSER_BUILD_TOOLS OFF CACHE INTERNAL "")

    if(EXISTS "${PROJECT_SOURCE_DIR}/deps/uriparser")
        FetchContent_Declare(liburiparser
            SOURCE_DIR "${PROJECT_SOURCE_DIR}/deps/uriparser"
        )
        message("-- Build using uriparser in deps/")
    else()
        FetchContent_Declare(liburiparser
            GIT_REPOSITORY https://github.com/uriparser/uriparser
            GIT_TAG uriparser-1.0.0
        )
        message("-- Build using uriparser from git repo")
    endif()

    FetchContent_MakeAvailable(liburiparser)

    set(uriparser_link_lib uriparser)
else()
    include(FindPkgConfig)

    pkg_search_module(PC_uriparser uriparser liburiparser QUIET IMPORTED_TARGET)
    if(PC_uriparser_FOUND)
        set(uriparser_link_lib PkgConfig::PC_uriparser)
    else()
        find_package(uriparser REQUIRED)
        set(uriparser_link_lib uriparser::uriparser)
    endif()
endif()
