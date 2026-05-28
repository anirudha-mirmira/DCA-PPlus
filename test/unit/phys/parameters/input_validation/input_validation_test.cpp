// Copyright (C) 2026 ETH Zurich
// Copyright (C) 2026 UT-Battelle, LLC
// All rights reserved.
//
// See LICENSE for terms of usage.
// See CITATION.md for citation guidelines, if DCA++ is used for scientific publications.
//
// Tests for issue #300: surface bad user input instead of silently substituting defaults.

#include "dca/config/haves_defines.hpp"
#include "dca/phys/parameters/output_parameters.hpp"
#include "dca/testing/gtest_h_w_warning_blocking.h"
#include "dca/io/json/json_reader.hpp"

// Bug #1: a non-existent output.directory should produce a clear error at parameter-read
// time, not a cryptic HDF5 crash later in the run. OutputParameters::readWrite parses the
// directory string without touching the disk; the new validate() method is where the
// existence check lives and where the throw is expected to come from.
TEST(InputValidationTest, MissingOutputDirectoryThrows) {
  dca::io::JSONReader reader;
  dca::phys::params::OutputParameters pars;

  reader.open_file(DCA_SOURCE_DIR
                   "/test/unit/phys/parameters/input_validation/missing_directory.json");
  pars.readWrite(reader);
  reader.close_file();

  EXPECT_THROW(pars.validate(), std::invalid_argument);
}
