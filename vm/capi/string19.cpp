#include "builtin/bytearray.hpp"
#include "builtin/fixnum.hpp"
#include "builtin/integer.hpp"
#include "builtin/nativemethod.hpp"
#include "builtin/object.hpp"
#include "builtin/string.hpp"
#include "capi/capi.hpp"
#include "capi/19/include/ruby/ruby.h"
#include "capi/19/include/ruby/encoding.h"

#include <string.h>

using namespace rubinius;
using namespace rubinius::capi;

namespace rubinius {
  namespace capi {
  }
}

extern "C" {
  VALUE rb_enc_str_new(const char *ptr, long len, rb_encoding *enc)
  {
    VALUE str = rb_str_new(ptr, len);
    rb_enc_associate(str, enc);
    return str;
  }

  VALUE rb_usascii_str_new_cstr(const char* ptr) {
    return rb_enc_str_new(ptr, strlen(ptr), rb_usascii_encoding());
  }

  int rb_enc_str_coderange(VALUE string) {
    // TODO
    return ENC_CODERANGE_7BIT;
  }

  VALUE rb_locale_str_new_cstr(const char *ptr) {
    // TODO
    return rb_str_new2(ptr);
  }

  VALUE rb_locale_str_new(const char* ptr, long len) {
    // TODO
    return rb_str_new(ptr, len);
  }

  VALUE rb_str_conv_enc(VALUE str, rb_encoding *from, rb_encoding *to) {
    // TODO
    return str;
  }

  VALUE rb_str_export_to_enc(VALUE str, rb_encoding *enc) {
    // TODO
    return rb_str_conv_enc(str, rb_enc_get(str), enc);
  }
}
