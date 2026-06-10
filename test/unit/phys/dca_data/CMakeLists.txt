# IO's unit tests

dca_add_gtest(dca_data_test
  FAST
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR}
  LIBS function ${DCA_LIBS} parallel_no_concurrency)

# Tests the real-space (DISORDERED_G0) disordered-G0 construction: k->r FT of the clean cluster-
# excluded G0, the two space-index unfolding, and the per-frequency disorder Dyson inversions.
dca_add_gtest(make_disordered_g0_test
  FAST
  GTEST_MAIN
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR};${FFTW_INCLUDE_DIR}
  LIBS function FFTW::Double ${DCA_LIBS} parallel_no_concurrency)

# Tests the DISORDERED_G0 walker Green's-function path: the dense disordered tau G0 (w->t Fourier
# with tail handling), the two-site walker akima storage, and absolute-site keying in build_G0_matrix.
dca_add_gtest(disordered_walker_g0_test
  FAST
  GTEST_MAIN
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR};${FFTW_INCLUDE_DIR}
  LIBS function FFTW::Double ${DCA_LIBS} parallel_no_concurrency)
