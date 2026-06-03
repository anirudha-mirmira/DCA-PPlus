# test/unit/phys/dca_step/cluster_solver/shared_tools/sp

dca_add_gtest(sp_accumulator_gpu_test
  CUDA
  GTEST_MAIN
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR}
  LIBS     FFTW::Double quantum_domains ${DCA_LIBS} ${DCA_KERNEL_LIBS}
  )

dca_add_gtest(sp_accumulator_complex_gpu_test
  CUDA
  FAST
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR}
  LIBS     FFTW::Double quantum_domains ${DCA_LIBS} ${DCA_KERNEL_LIBS}
  )


dca_add_gtest(sp_accumulator_single_meas_G_test
  CUDA
  GTEST_MAIN
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR}
  LIBS     FFTW::Double quantum_domains ${DCA_LIBS} ${DCA_KERNEL_LIBS}
  )

# CPU-only test of the two-site (DISORDERED_G0) sp accumulator: correct two-site indexing and
# off-diagonal (r1 != r2) population of the M function. FAST (no CUDA) so it runs on CPU builds.
dca_add_gtest(sp_accumulator_disorder_test
  FAST
  GTEST_MAIN
  INCLUDE_DIRS ${DCA_INCLUDE_DIRS};${PROJECT_SOURCE_DIR}
  LIBS     FFTW::Double quantum_domains ${DCA_LIBS}
  )

#;mc_kernels
