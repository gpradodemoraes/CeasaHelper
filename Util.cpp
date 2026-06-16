#include "pch.h"
#include "Util.hpp"

static std::unique_ptr<CString> CollapseWhitespaceToPipe(const CString &input) {
	std::unique_ptr<CString> result = std::make_unique<CString>();
	bool inWhitespace = false;

	for (int i = 0; i < input.GetLength(); i++) {
		TCHAR ch = input[i];
		if (_istspace(ch)) {
			if (!inWhitespace) {
				*result += _T('|');
				inWhitespace = true;
			}
		} else {
			*result += ch;
			inWhitespace = false;
		}
	}

	return result;
}

std::unique_ptr<std::vector<CString>> parse_words(CString *input) {
	std::unique_ptr<CString> clean = CollapseWhitespaceToPipe(*input);
	std::unique_ptr<std::vector<CString>> words = std::make_unique<std::vector<CString>>();
	int start = 0;
	int end = 0;
	while ((end = clean->Find(_T('|'), start)) != -1) {
		words->push_back(clean->Mid(start, end - start));
		start = end + 1;
	}
	if (start < clean->GetLength()) {
		words->push_back(clean->Mid(start));
	}
	return words;
}

double convert_brazilian_number_format(CString *number_str) {
	number_str->Remove(_T('.'));
	number_str->Replace(_T(','), _T('.'));
	return _tstof(*number_str);
}
