#include <memory>
#include <vector>
#include <afxstr.h>

std::unique_ptr<std::vector<CString>> parse_words(CString *input);

double convert_brazilian_number_format(CString *number_str);
