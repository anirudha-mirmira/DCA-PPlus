#!/bin/bash

# Run all tc calculations on a local workstation (no scheduler, single process).
# NOTE: Do not use mpiexec/multi-process with the threaded solver; a code bug
# causes incorrect density measurements when MPI is combined with
# shared-walk-and-accumulation-thread.

RUN_DCA="../../applications/dca/main_dca"
date

$RUN_DCA ./T=1/input_sp.json
$RUN_DCA ./T=0.75/input_sp.json
$RUN_DCA ./T=0.5/input_sp.json
$RUN_DCA ./T=0.25/input_sp.json
$RUN_DCA ./T=0.125/input_sp.json
$RUN_DCA ./T=0.1/input_sp.json
$RUN_DCA ./T=0.1/input_tp.json
$RUN_DCA ./T=0.09/input_sp.json
$RUN_DCA ./T=0.09/input_tp.json
$RUN_DCA ./T=0.08/input_sp.json
$RUN_DCA ./T=0.08/input_tp.json
$RUN_DCA ./T=0.07/input_sp.json
$RUN_DCA ./T=0.07/input_tp.json

date
