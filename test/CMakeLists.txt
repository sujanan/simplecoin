set(LIBS
    "-lssl"
    "-lcrypto"
    "-lcheck"
)

# test1: test sha256 hash generating function
set(TEST test_gen_sha256)
add_executable(${TEST} test.h ${TEST}.c)
target_link_libraries(${TEST} libsimplecoin ${LIBS})
add_test(NAME ${TEST} COMMAND ${TEST})

# test2: test strlen of all block data
set(TEST test_block_strlen)
add_executable(${TEST} test.h ${TEST}.c)
target_link_libraries(${TEST} libsimplecoin ${LIBS})
add_test(NAME ${TEST} COMMAND ${TEST})
