# Honor per-interactive-shell startup file
if [ -f ~/.bashrc ]; then . ~/.bashrc; fi


# init environment modules
test -e /run/current-system/profile/init/bash && source /run/current-system/profile/init/bash
test -e $MODULESHOME/modulefiles && module unuse $MODULESHOME/modulefiles
test -e /etc/modules && module use /etc/modules
HISTCONTROL=erasedups:ignorespace HISTSIZE= HISTFILESIZE=
shopt -s histverify histappend
alias rm='rm --preserve-root --one-file-system'
alias mkdir='mkdir -p'
alias ls='ls --color=auto --group-directories-first'
alias gdb='gdb -q --args'
alias ps='ps --ppid 2 -p 2 --deselect'
