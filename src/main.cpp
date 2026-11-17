#include <cstdio>
#include <string_view>

int main(int argc, char* argv[]) {
	if (argc < 1) [[unlikely]] {
		return 1;
	}

	const std::string_view binary_name{argv[0]};
	std::printf("Starter template running: %.*s\n", static_cast<int>(binary_name.size()),
	            binary_name.data());

	return 0;
}
