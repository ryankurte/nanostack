


include_directories(
    nanostack
    source
    libs
    libs/libservice
    libs/nanostack-event-loop
    libs/coap-service
    libs/mbed-coap
    libs/mbed-coap/source/include
    libs/coap-service/coap-service
    libs/coap-service/source/include
    source/Service_Libs/mdns
    source/Service_Libs/mdns/fnet/fnet_stack
    source/Service_Libs/mdns/fnet/fnet_stack/stack
    source/Service_Libs/mdns/fnet/fnet_stack/services/serial
)
FILE(GLOB_RECURSE LIBSERVICE_SOURCES
	${CMAKE_CURRENT_LIST_DIR}/libs/libservice/*.c
    ${CMAKE_CURRENT_LIST_DIR}/libs/coap-service/source/*.c
    ${CMAKE_CURRENT_LIST_DIR}/libs/mbed-coap/*.c
)

FILE(GLOB_RECURSE NANOSTACK_SOURCES
	${CMAKE_CURRENT_LIST_DIR}/source/*.c
)

add_library(nanostack ${NANOSTACK_SOURCES} ${LIBSERVICE_SOURCES}) 
