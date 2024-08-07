#include <boost/program_options.hpp>
#include <iostream>
#include <string>


#include "version.hpp"

std::string fizzbuzz(int n) {
	std::string out = "";
	if (n % 3 == 0) {
		out += "fizz";
	} if (n % 5 == 0) {
		return out += "buzz";
	} if (out == "") {
		out = std::to_string(n);
	}
	return out;
}

int main(int argc, char const *argv[])
{
	namespace po = boost::program_options;
	po::variables_map vm;
	try {
		po::positional_options_description p;
		p.add("number", 1);
		po::options_description desc{"Options"};
		desc.add_options()
		("help,h", "help screen, show this message")
		("version" , "show version number")
		("number", po::value<int>(), "number to fizz-buzz")
		("beginn,b", po::value<int>()->default_value(1), "start number")
		("end,e", po::value<int>()->default_value(100), "end number")
		("delimiter,d", po::value<std::string>()->default_value(std::string(", ")), "delimiter");
		// ("address,a", po::value<std::string>()->default_value("127.0.0.1"), "server address")
		// ("port,p", po::value<unsigned>()->default_value(3030), "server port")
		// ("doc_root,d", po::value<std::string>()->default_value("..\\..\\html\\"), "document root")
		// ("threads,t", po::value<unsigned>()->default_value(1), "server threads");
		// po::store(po::parse_command_line(argc, argv, desc), vm); // suitable if no positional arguments
		po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
		po::notify(vm); // important if this->notifier() is set on an option

		if (vm.count("version")) {
			std::cout << "version: " << std::string(GIT_VERSION_STRING) << std::endl;
			return 0;
		}
		if (vm.count("help")) {
			std::cout << desc << "\nversion: " << std::string(GIT_VERSION_STRING) << '\n' << "developed by Lars Bornträger" << std::endl;
			return 0;
		}
	} catch (const po::error &ex) { std::cerr << ex.what() << std::endl; }

	if (vm.count("number")) {
		std::cout << fizzbuzz(vm["number"].as<int>()) << std::endl;
		return 0;
	}

	int beginn = vm["beginn"].as<int>();
	int end = vm["end"].as<int>();
	if (beginn > end) {
		std::cerr << "error: beginn > end" << std::endl;
	}
	std::string delimiter = vm["delimiter"].as<std::string>();
	for (int i = beginn; i <= end; i++) {
		std::cout << fizzbuzz(i) << delimiter;
	}
	std::cout << std::endl;
	return 0;
}




