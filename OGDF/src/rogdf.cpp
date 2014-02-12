#include "rogdf.h"

IntegerVector rogdf_version() {

  IntegerVector version = 
    IntegerVector::create(_["major"] = 2012,
			  _["minor"] = 7,
			  _["patch"] = 0);
  return version;

}
