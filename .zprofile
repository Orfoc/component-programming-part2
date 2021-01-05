# Honor system-wide environment variables
source /etc/profile


# init environment modules
test -e /run/current-system/profile/init/zsh && source /run/current-system/profile/init/zsh
test -e $MODULESHOME/modulefiles && module unuse $MODULESHOME/modulefiles
test -e /etc/modules && module use /etc/modules
