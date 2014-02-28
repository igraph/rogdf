#include "rogdf.h"

namespace rogdf {

  IntegerVector rogdf_version() {
    return IntegerVector::create(_["major"] = 2012,
				 _["minor"] = 7,
				 _["patch"] = 0);
  }

} // namespace rogdf
