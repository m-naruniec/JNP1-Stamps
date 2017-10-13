#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <vector>
#include <tuple>

typedef std::tuple<unsigned long long,
	std::string, double, std::string, std::string> stamp;
typedef std::vector<stamp> album;
typedef std::pair<unsigned long long, unsigned long long> query;

bool match_pattern(const std::string& input,
				std::smatch& match, const std::string& pattern) {
	const std::regex query_regex(pattern);
	return std::regex_match(input, match, query_regex);
}

bool match_stamp(const std::string& input, std::smatch& match) {
	std::string stamp_pattern = "(\\s*)";
	stamp_pattern += "((\\S.*\\S)|(\\S))";
	// ^ Stamp's name, index = 2
	stamp_pattern += "(\\s+)";
	stamp_pattern += "(([[:digit:]]+)((\\.|,)([[:digit:]]+)?)?)";
	// ^ Stamp's price, index = 6
	stamp_pattern += "(\\s+)";
	stamp_pattern += "([[:digit:]]+)";
	// ^ Stamp's year, index = 12
	stamp_pattern += "(\\s+)";
	stamp_pattern += "((\\S.*\\S)|(\\S))";
	// ^ Stamp's postoffice, index = 14
	stamp_pattern += "(\\s*)";
	return match_pattern(input, match, stamp_pattern);
}

bool match_query(const std::string& input, std::smatch& match) {
	const static std::string query_pattern =
		"(\\s*)([[:digit:]]+)(\\s+)([[:digit:]]+)(\\s*)";
	// ^ Interval, index = 2 and index = 4
	return match_pattern(input, match, query_pattern);
}

bool double_space(const char c1, const char& c2) {
	return c1 == ' ' && c1 == c2;
}

std::string reduce_spaces(std::string input) {
	std::string::const_iterator new_end =
		std::unique(input.begin(), input.end(), double_space);
	input.erase(new_end, input.end());
	return input;
}

void add_stamp(const std::smatch& match, album& current_album) {
	unsigned long long year = std::stoull(match[12]);
	std::string post = reduce_spaces(match[14]);
	std::string price_string = match[6];
	std::string price_orig_string = price_string;
	if (match[9] == ",")
		price_string.replace(price_string.find(","), 1, ".");

	double price_double = std::stod(price_string);
	std::string name = reduce_spaces(match[2]);

	stamp new_stamp(year, post, price_double, name, price_orig_string);
	current_album.push_back(new_stamp);
}

stamp lowest_stamp_of(unsigned long long year) {
	stamp new_stamp(year, "", 0.0, "", "");
	return new_stamp;
}

void print_stamp(stamp& current_stamp) {
	std::cout << std::get<0>(current_stamp)
	<< " " << std::get<1>(current_stamp)
	<< " " << std::get<4>(current_stamp)
	<< " " << std::get<3>(current_stamp) << std::endl;
	return;
}

void answer_query(query& current_query, album& current_album) {
	stamp lowest_value = lowest_stamp_of(current_query.first);
	stamp above_value = lowest_stamp_of(current_query.second + 1);

	album::iterator first_match =
		std::lower_bound(current_album.begin(),
						current_album.end(), lowest_value);
	album::iterator above_match =
		std::upper_bound(first_match,
						current_album.end(), above_value);

	std::for_each(first_match, above_match, print_stamp);
	return;
}

void report_error(const int current_line, const std::string& input) {
	std::cerr << "Error in line " << current_line <<":"
		<< input << std::endl;
	return;
}

void process_input() {
	album current_album;
	std::string input;
	bool during_queries = false;
	int current_line = 0;

	while(getline(std::cin, input)) {
		std::smatch match;
		current_line++;

		if (match_stamp(input, match)) {
			if (during_queries)
				report_error(current_line, input);
			else add_stamp(match, current_album);
		}

		else if (match_query(input, match)) {
			query new_query(std::stoull(match[2]), std::stoull(match[4]));
			if(new_query.first <= new_query.second) {
				if(!during_queries) {
					std::sort(current_album.begin(), current_album.end());
					during_queries = true;
				}
				answer_query(new_query, current_album);
			}
			else report_error(current_line, input);
		}

		else report_error(current_line, input);
	}
}

int main() {
	std::ios_base::sync_with_stdio(0);
	process_input();
	return 0;
}
