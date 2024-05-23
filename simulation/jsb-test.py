import jsbsim
import time

fdm = jsbsim.FGFDMExec(None)  # Use JSBSim default aircraft data.
fdm.load_script('scripts/c1723.xml')
fdm.set_output_directive('data_output/flightgear.xml')


fdm.run_ic()

while fdm.run():
  latitude = fdm['position/lat-gc-rad']
  print(latitude)