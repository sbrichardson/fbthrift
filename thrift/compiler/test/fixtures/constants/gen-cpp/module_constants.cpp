/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "thrift/compiler/test/fixtures/constants/gen-cpp/module_constants.h"



constexpr int32_t const module_constants::myInt_;
constexpr char const *const module_constants::name_;
std::vector<std::map<std::string, int32_t> >  const &module_constants::states() {
  static auto const instance([]() {
    std::vector<std::map<std::string, int32_t> >  value;

    std::map<std::string, int32_t>  tmp0;
    tmp0.insert(std::make_pair("San Diego", 3211000));
    tmp0.insert(std::make_pair("Sacramento", 479600));
    tmp0.insert(std::make_pair("SF", 837400));

    value.push_back(tmp0);
    std::map<std::string, int32_t>  tmp1;
    tmp1.insert(std::make_pair("New York", 8406000));
    tmp1.insert(std::make_pair("Albany", 98400));

    value.push_back(tmp1);

    return value;
  }());
  return instance;
}
constexpr double const module_constants::x_;
constexpr double const module_constants::y_;
constexpr double const module_constants::z_;
Internship const &module_constants::instagram() {
  static auto const instance([]() {
    Internship value;

    value.weeks = 12;
    value.title = "Software Engineer";
    value.__isset.title = true;
    value.employer = (Company)3;
    value.__isset.employer = true;

    return value;
  }());
  return instance;
}
std::vector<Range>  const &module_constants::kRanges() {
  static auto const instance([]() {
    std::vector<Range>  value;

    Range tmp2;
    tmp2.min = 1;
    tmp2.max = 2;

    value.push_back(tmp2);
    Range tmp3;
    tmp3.min = 5;
    tmp3.max = 6;

    value.push_back(tmp3);

    return value;
  }());
  return instance;
}
std::vector<Internship>  const &module_constants::internList() {
  static auto const instance([]() {
    std::vector<Internship>  value;

    Internship tmp4;
    tmp4.weeks = 12;
    tmp4.title = "Software Engineer";
    tmp4.__isset.title = true;
    tmp4.employer = (Company)3;
    tmp4.__isset.employer = true;

    value.push_back(tmp4);
    Internship tmp5;
    tmp5.weeks = 10;
    tmp5.title = "Sales Intern";
    tmp5.__isset.title = true;
    tmp5.employer = (Company)0;
    tmp5.__isset.employer = true;

    value.push_back(tmp5);

    return value;
  }());
  return instance;
}
constexpr char const *const module_constants::apostrophe_;
constexpr char const *const module_constants::tripleApostrophe_;
constexpr char const *const module_constants::quotationMark_;
constexpr char const *const module_constants::backslash_;
constexpr char const *const module_constants::escaped_a_;
std::map<std::string, int32_t>  const &module_constants::char2ascii() {
  static auto const instance([]() {
    std::map<std::string, int32_t>  value;

    value.insert(std::make_pair("'", 39));
    value.insert(std::make_pair("\"", 34));
    value.insert(std::make_pair("\\", 92));
    value.insert(std::make_pair("\x61", 97));

    return value;
  }());
  return instance;
}
std::vector<std::string>  const &module_constants::escaped_strings() {
  static auto const instance([]() {
    std::vector<std::string>  value;

    value.push_back("\x61");
    value.push_back("\xab");
    value.push_back("\x6a");
    value.push_back("\xa6");
    value.push_back("\x61yyy");
    value.push_back("\xabyyy");
    value.push_back("\x6ayyy");
    value.push_back("\xa6yyy");
    value.push_back("zzz\x61");
    value.push_back("zzz\xab");
    value.push_back("zzz\x6a");
    value.push_back("zzz\xa6");
    value.push_back("zzz\x61yyy");
    value.push_back("zzz\xabyyy");
    value.push_back("zzz\x6ayyy");
    value.push_back("zzz\xa6yyy");

    return value;
  }());
  return instance;
}
constexpr bool const module_constants::false_c_;
constexpr bool const module_constants::true_c_;
constexpr int8_t const module_constants::zero_byte_;
constexpr int16_t const module_constants::zero16_;
constexpr int32_t const module_constants::zero32_;
constexpr int64_t const module_constants::zero64_;
constexpr double const module_constants::zero_dot_zero_;
constexpr char const *const module_constants::empty_string_;
std::vector<int32_t>  const &module_constants::empty_int_list() {
  static auto const instance([]() {
    std::vector<int32_t>  value;


    return value;
  }());
  return instance;
}
std::vector<std::string>  const &module_constants::empty_string_list() {
  static auto const instance([]() {
    std::vector<std::string>  value;


    return value;
  }());
  return instance;
}
std::set<int32_t>  const &module_constants::empty_int_set() {
  static auto const instance([]() {
    std::set<int32_t>  value;


    return value;
  }());
  return instance;
}
std::set<std::string>  const &module_constants::empty_string_set() {
  static auto const instance([]() {
    std::set<std::string>  value;


    return value;
  }());
  return instance;
}
std::map<int32_t, int32_t>  const &module_constants::empty_int_int_map() {
  static auto const instance([]() {
    std::map<int32_t, int32_t>  value;


    return value;
  }());
  return instance;
}
std::map<int32_t, std::string>  const &module_constants::empty_int_string_map() {
  static auto const instance([]() {
    std::map<int32_t, std::string>  value;


    return value;
  }());
  return instance;
}
std::map<std::string, int32_t>  const &module_constants::empty_string_int_map() {
  static auto const instance([]() {
    std::map<std::string, int32_t>  value;


    return value;
  }());
  return instance;
}
std::map<std::string, std::string>  const &module_constants::empty_string_string_map() {
  static auto const instance([]() {
    std::map<std::string, std::string>  value;


    return value;
  }());
  return instance;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

moduleConstants::moduleConstants() {
  myInt = module_constants::myInt();
  name = module_constants::name();
  states = module_constants::states();
  x = module_constants::x();
  y = module_constants::y();
  z = module_constants::z();
  instagram = module_constants::instagram();
  kRanges = module_constants::kRanges();
  internList = module_constants::internList();
  apostrophe = module_constants::apostrophe();
  tripleApostrophe = module_constants::tripleApostrophe();
  quotationMark = module_constants::quotationMark();
  backslash = module_constants::backslash();
  escaped_a = module_constants::escaped_a();
  char2ascii = module_constants::char2ascii();
  escaped_strings = module_constants::escaped_strings();
  false_c = module_constants::false_c();
  true_c = module_constants::true_c();
  zero_byte = module_constants::zero_byte();
  zero16 = module_constants::zero16();
  zero32 = module_constants::zero32();
  zero64 = module_constants::zero64();
  zero_dot_zero = module_constants::zero_dot_zero();
  empty_string = module_constants::empty_string();
  empty_int_list = module_constants::empty_int_list();
  empty_string_list = module_constants::empty_string_list();
  empty_int_set = module_constants::empty_int_set();
  empty_string_set = module_constants::empty_string_set();
  empty_int_int_map = module_constants::empty_int_int_map();
  empty_int_string_map = module_constants::empty_int_string_map();
  empty_string_int_map = module_constants::empty_string_int_map();
  empty_string_string_map = module_constants::empty_string_string_map();
}

#pragma GCC diagnostic pop



