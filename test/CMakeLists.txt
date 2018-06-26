add_executable(checks test_test.c)

target_link_libraries(checks libsimplecoin)

add_test(NAME sample_test
	COMMAND checks
)
