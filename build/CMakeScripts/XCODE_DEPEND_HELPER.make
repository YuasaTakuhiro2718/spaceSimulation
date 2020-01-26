# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.simulation.Debug:
/Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/Debug/simulation:
	/bin/rm -f /Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/Debug/simulation


PostBuild.simulation.Release:
/Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/Release/simulation:
	/bin/rm -f /Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/Release/simulation


PostBuild.simulation.MinSizeRel:
/Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/MinSizeRel/simulation:
	/bin/rm -f /Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/MinSizeRel/simulation


PostBuild.simulation.RelWithDebInfo:
/Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/RelWithDebInfo/simulation:
	/bin/rm -f /Users/yuasatakuhiroshi/Documents/Github/space_simulation/build/RelWithDebInfo/simulation




# For each target create a dummy ruleso the target does not have to exist
