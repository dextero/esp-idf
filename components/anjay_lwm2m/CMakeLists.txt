set(COMPONENT_ADD_INCLUDEDIRS
    Anjay/avs_commons/git/stream/include_public
    Anjay/avs_commons/git/stream/md5/include_public
    Anjay/avs_commons/git/stream/net/include_public
    Anjay/avs_commons/git/vector/include_public
    Anjay/avs_commons/git/http/include_public
    Anjay/avs_commons/git/rbtree/include_public
    Anjay/avs_commons/git/include_public
    Anjay/avs_commons/git/log/include_public
    Anjay/avs_commons/git/coap/include_public
    Anjay/avs_commons/git/compat/threading/include_public
    Anjay/avs_commons/git/utils/include_public
    Anjay/avs_commons/git/list/include_public
    Anjay/avs_commons/git/persistence/include_public
    Anjay/avs_commons/git/algorithm/include_public
    Anjay/avs_commons/git/net/include_public
    Anjay/avs_commons/git/buffer/include_public
    Anjay/avs_commons/git/sched/include_public
    Anjay/avs_commons/git/unit/include_public
    Anjay/include_public
    Anjay/modules/fw_update/include_public
    Anjay/modules/server/include_public
    Anjay/modules/attr_storage/include_public
    Anjay/modules/access_control/include_public
    Anjay/modules/security/include_public)
set(COMPONENT_SRCS "anjay.c")
set(COMPONENT_REQUIRES lwip mbedtls)

register_component()

# Workarounds
set(WITH_DEMO OFF CACHE INTERNAL "")
set(WITH_AVS_UNIT OFF CACHE INTERNAL "")
set(WITH_AVS_HTTP_ZLIB OFF CACHE INTERNAL "")
set(WITH_HTTP_DOWNLOAD ON CACHE INTERNAL "")
set(HAVE_MATH_LIBRARY ON CACHE INTERNAL "")

set(AVS_LOG_WITH_TRACE  ON CACHE INTERNAL "")
set(WITH_INTERNAL_LOGS  ON CACHE INTERNAL "")
set(WITH_INTERNAL_TRACE ON CACHE INTERNAL "")
#set(WITH_MBEDTLS_LOGS ON CACHE INTERNAL "")

set(POSIX_COMPAT_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/Anjay/avs_commons/git/compat/lwip-posix-compat.h" CACHE INTERNAL "")
set(WITH_POSIX_AVS_TIME ON CACHE INTERNAL "")
set(WITH_AVS_COMPAT_THREADING OFF CACHE INTERNAL "")

include_directories($<TARGET_PROPERTY:idf_component_lwip,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:idf_component_newlib,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:idf_component_esp_common,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:idf_component_freertos,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:idf_component_xtensa,INTERFACE_INCLUDE_DIRECTORIES>
                    $<TARGET_PROPERTY:idf_component_esp32,INCLUDE_DIRECTORIES>)

# oh god why
function(install)
    if (NOT ANJAY_INSTALL_DISABLE)
        _install(${ARGN})
    endif()
endfunction()

set(ANJAY_INSTALL_DISABLE ON)

# Import Anjay library targets
add_subdirectory(Anjay)

set(ANJAY_INSTALL_DISABLE OFF)

# Link mbedtls libraries to component library
target_link_libraries(${COMPONENT_TARGET} PUBLIC anjay_static)
