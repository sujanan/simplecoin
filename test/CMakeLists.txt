set(LIBS
	"-lssl"
	"-lcrypto"
)

add_executable(checks 
	test.h
	test_gen_sha256.c
)

target_link_libraries(checks libsimplecoin ${LIBS})

add_test(NAME sample_test
	COMMAND checks
)
