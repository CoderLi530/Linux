Xshell 8 (Build 0067)
Copyright (c) 2024 NetSarang Computer, Inc. All rights reserved.

Type `help' to learn how to use Xshell prompt.
[C:\~]$ 

Connecting to 113.45.157.139:22...
Connection established.
To escape to local shell, press 'Ctrl+Alt+]'.

WARNING! The remote SSH server rejected X11 forwarding request.
Last login: Mon May 12 18:31:49 2025 from 183.217.155.100
	
	Welcome to Huawei Cloud Service

[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ ll
total 20
-rw-rw-r-- 1 lzh lzh   77 May 12 16:58 makefile
-rwxrwxr-x 1 lzh lzh 9128 May 12 20:09 myshell
-rw-rw-r-- 1 lzh lzh 1845 May 12 20:24 myshell.c
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
myshell.c: In function ‘interact’:
myshell.c:38:3: error: invalid use of void expression
   printf(LEFT"%s@%s %s"RIGHT""LABLE" ", getuser(), gethostname(), getpwd());
   ^
myshell.c: In function ‘main’:
myshell.c:71:7: error: ‘_argc’ undeclared (first use in this function)
   if (_argc == 2 && argv[0] == "cd")
       ^
myshell.c:71:7: note: each undeclared identifier is reported only once for each function it appears in
make: *** [myshell] Error 1
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
myshell.c: In function ‘interact’:
myshell.c:38:3: error: invalid use of void expression
   printf(LEFT"%s@%s %s"RIGHT""LABLE" ", getuser(), gethostname(), getpwd());
   ^
make: *** [myshell] Error 1
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 ]$ ll
[lzh@hcss-ecs-1552 ]$ ls -a
.  ..  .bash_history  .bash_logout  .bash_profile  .bashrc  .config  .cquery  .install.sh  .LfCache  .local  makefile  myshell	myshell.c  .pki  .vim  .VimForCpp  .vimrc  .ycm_extra_conf.py
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ ll
[lzh@hcss-ecs-1552 ]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 ]$ cd ..
[lzh@hcss-ecs-1552 ]$ cd ..
[lzh@hcss-ecs-1552 ]$ pwd
/home/lzh
[lzh@hcss-ecs-1552 ]$ cd ..
[lzh@hcss-ecs-1552 ]$ ll
[lzh@hcss-ecs-1552 ]$ pd^Hwd^H^H^H^H^H^H^H^H^H^H^H^H^H
[lzh@hcss-ecs-1552 ]$ pwd
/home/lzh
[lzh@hcss-ecs-1552 ]$ cd ..
[lzh@hcss-ecs-1552 ]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 ]$ ld^H^H^H
[lzh@hcss-ecs-1552 ]$ claer^H^H^H
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ cd ^H^H^H
[lzh@hcss-ecs-1552 ~]$ pwd
/home/lzh
[lzh@hcss-ecs-1552 ~]$ cd ..
[lzh@hcss-ecs-1552 home]$ pwd
/home
[lzh@hcss-ecs-1552 home]$ ^C
[lzh@hcss-ecs-1552 home]$ ./myshell
-bash: ./myshell: No such file or directory
[lzh@hcss-ecs-1552 home]$ ./myshell
-bash: ./myshell: No such file or directory
[lzh@hcss-ecs-1552 home]$ ls
lzh
[lzh@hcss-ecs-1552 home]$ cd .
[lzh@hcss-ecs-1552 home]$ ll
total 4
drwx------ 7 lzh lzh 4096 May 13 14:11 lzh
[lzh@hcss-ecs-1552 home]$ cd ~
[lzh@hcss-ecs-1552 ~]$ ll
total 24
-rw-rw-r-- 1 lzh lzh    77 May 12 16:58 makefile
-rwxrwxr-x 1 lzh lzh 13456 May 13 14:11 myshell
-rw-rw-r-- 1 lzh lzh  1977 May 13 14:11 myshell.c
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ll^Hs
[lzh@hcss-ecs-1552 ]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
myshell.c: In function ‘main’:
myshell.c:75:5: error: invalid use of void expression
     printf("%s", getpwd("PWD"));
     ^
make: *** [myshell] Error 1
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ cd ..
/home/lzh[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ cd..
[lzh@hcss-ecs-1552 ]$ cd ..
/home[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ export aaa = 23ll3jr3j2r
-bash: export: `=': not a valid identifier
-bash: export: `23ll3jr3j2r': not a valid identifier
[lzh@hcss-ecs-1552 ~]$ export a = slfsljdf
-bash: export: `=': not a valid identifier
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ export a=slfsjfew
[lzh@hcss-ecs-1552 ~]$ env
XDG_SESSION_ID=25
HOSTNAME=hcss-ecs-1552
TERM=xterm
SHELL=/bin/bash
HISTSIZE=10000
SSH_CLIENT=183.217.30.158 3214 22
OLDPWD=/home
SSH_TTY=/dev/pts/0
USER=lzh
LD_LIBRARY_PATH=:/home/lzh/.VimForCpp/vim/bundle/YCM.so/el7.x86_64
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=01;05;37;41:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=01;36:*.au=01;36:*.flac=01;36:*.mid=01;36:*.midi=01;36:*.mka=01;36:*.mp3=01;36:*.mpc=01;36:*.ogg=01;36:*.ra=01;36:*.wav=01;36:*.axa=01;36:*.oga=01;36:*.spx=01;36:*.xspf=01;36:
MAIL=/var/spool/mail/lzh
PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/lzh/.local/bin:/home/lzh/bin
a=slfsjfew
PWD=/home/lzh
LANG=en_US.UTF-8
HISTCONTROL=ignoredups
SHLVL=1
HOME=/home/lzh
LOGNAME=lzh
SSH_CONNECTION=183.217.30.158 3214 192.168.15.169 22
LESSOPEN=||/usr/bin/lesspipe.sh %s
XDG_RUNTIME_DIR=/run/user/1000
HISTTIMEFORMAT=%F %T lzh 
_=/usr/bin/env
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ ll
total 24
-rw-rw-r-- 1 lzh lzh    77 May 12 16:58 makefile
-rwxrwxr-x 1 lzh lzh 13400 May 13 14:24 myshell
-rw-rw-r-- 1 lzh lzh  2352 May 13 14:41 myshell.c
[lzh@hcss-ecs-1552 ~]$ env
XDG_SESSION_ID=25
HOSTNAME=hcss-ecs-1552
TERM=xterm
SHELL=/bin/bash
HISTSIZE=10000
SSH_CLIENT=183.217.30.158 3214 22
OLDPWD=/home
SSH_TTY=/dev/pts/0
USER=lzh
LD_LIBRARY_PATH=:/home/lzh/.VimForCpp/vim/bundle/YCM.so/el7.x86_64
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=01;05;37;41:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=01;36:*.au=01;36:*.flac=01;36:*.mid=01;36:*.midi=01;36:*.mka=01;36:*.mp3=01;36:*.mpc=01;36:*.ogg=01;36:*.ra=01;36:*.wav=01;36:*.axa=01;36:*.oga=01;36:*.spx=01;36:*.xspf=01;36:
MAIL=/var/spool/mail/lzh
PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/lzh/.local/bin:/home/lzh/bin
a=slfsjfew
PWD=/home/lzh
LANG=en_US.UTF-8
HISTCONTROL=ignoredups
SHLVL=1
HOME=/home/lzh
LOGNAME=lzh
SSH_CONNECTION=183.217.30.158 3214 192.168.15.169 22
LESSOPEN=||/usr/bin/lesspipe.sh %s
XDG_RUNTIME_DIR=/run/user/1000
HISTTIMEFORMAT=%F %T lzh 
_=/usr/bin/env
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ export b=sjfjwefo
[lzh@hcss-ecs-1552 ~]$ env
XDG_SESSION_ID=25
HOSTNAME=hcss-ecs-1552
TERM=xterm
SHELL=/bin/bash
HISTSIZE=10000
SSH_CLIENT=183.217.30.158 3214 22
OLDPWD=/home
SSH_TTY=/dev/pts/0
USER=lzh
LD_LIBRARY_PATH=:/home/lzh/.VimForCpp/vim/bundle/YCM.so/el7.x86_64
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=01;05;37;41:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=01;36:*.au=01;36:*.flac=01;36:*.mid=01;36:*.midi=01;36:*.mka=01;36:*.mp3=01;36:*.mpc=01;36:*.ogg=01;36:*.ra=01;36:*.wav=01;36:*.axa=01;36:*.oga=01;36:*.spx=01;36:*.xspf=01;36:
MAIL=/var/spool/mail/lzh
PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/lzh/.local/bin:/home/lzh/bin
a=slfsjfew
PWD=/home/lzh
b=sjfjwefo
LANG=en_US.UTF-8
HISTCONTROL=ignoredups
SHLVL=1
HOME=/home/lzh
LOGNAME=lzh
SSH_CONNECTION=183.217.30.158 3214 192.168.15.169 22
LESSOPEN=||/usr/bin/lesspipe.sh %s
XDG_RUNTIME_DIR=/run/user/1000
HISTTIMEFORMAT=%F %T lzh 
_=/usr/bin/env
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ export -n a
[lzh@hcss-ecs-1552 ~]$ export -n b
[lzh@hcss-ecs-1552 ~]$ env
XDG_SESSION_ID=25
HOSTNAME=hcss-ecs-1552
TERM=xterm
SHELL=/bin/bash
HISTSIZE=10000
SSH_CLIENT=183.217.30.158 3214 22
OLDPWD=/home
SSH_TTY=/dev/pts/0
USER=lzh
LD_LIBRARY_PATH=:/home/lzh/.VimForCpp/vim/bundle/YCM.so/el7.x86_64
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=01;05;37;41:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=01;36:*.au=01;36:*.flac=01;36:*.mid=01;36:*.midi=01;36:*.mka=01;36:*.mp3=01;36:*.mpc=01;36:*.ogg=01;36:*.ra=01;36:*.wav=01;36:*.axa=01;36:*.oga=01;36:*.spx=01;36:*.xspf=01;36:
MAIL=/var/spool/mail/lzh
PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/lzh/.local/bin:/home/lzh/bin
PWD=/home/lzh
LANG=en_US.UTF-8
HISTCONTROL=ignoredups
SHLVL=1
HOME=/home/lzh
LOGNAME=lzh
SSH_CONNECTION=183.217.30.158 3214 192.168.15.169 22
LESSOPEN=||/usr/bin/lesspipe.sh %s
XDG_RUNTIME_DIR=/run/user/1000
HISTTIMEFORMAT=%F %T lzh 
_=/usr/bin/env
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
myshell.c: In function ‘buildcommand’:
myshell.c:65:11: error: expected expression before ‘)’ token
   else if()
           ^
make: *** [myshell] Error 1
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ echo $?
0
[lzh@hcss-ecs-1552 ~]$ echo $?
0
[lzh@hcss-ecs-1552 ~]$ vim myshell.c\
> ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ v^H
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ ls
[lzh@hcss-ecs-1552 ]$ ll
[lzh@hcss-ecs-1552 ]$ ls
[lzh@hcss-ecs-1552 ]$ pwd
[lzh@hcss-ecs-1552 ]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make clean
rm -f myshell
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ ll
total 8
-rw-rw-r-- 1 lzh lzh   77 May 12 16:58 makefile
-rw-rw-r-- 1 lzh lzh 2353 May 13 14:49 myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ll
total 24
-rw-rw-r-- 1 lzh lzh    77 May 12 16:58 makefile
-rwxrwxr-x 1 lzh lzh 13528 May 13 14:49 myshell
-rw-rw-r-- 1 lzh lzh  2353 May 13 14:49 myshell.c
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ls
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ echo $?
$?
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ echo $
$
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ env
XDG_SESSION_ID=25
HOSTNAME=hcss-ecs-1552
TERM=xterm
SHELL=/bin/bash
HISTSIZE=10000
SSH_CLIENT=183.217.30.158 3214 22
OLDPWD=/home
SSH_TTY=/dev/pts/0
USER=lzh
LD_LIBRARY_PATH=:/home/lzh/.VimForCpp/vim/bundle/YCM.so/el7.x86_64
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=01;05;37;41:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=01;36:*.au=01;36:*.flac=01;36:*.mid=01;36:*.midi=01;36:*.mka=01;36:*.mp3=01;36:*.mpc=01;36:*.ogg=01;36:*.ra=01;36:*.wav=01;36:*.axa=01;36:*.oga=01;36:*.spx=01;36:*.xspf=01;36:
MAIL=/var/spool/mail/lzh
PATH=/usr/local/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/home/lzh/.local/bin:/home/lzh/bin
PWD=/home/lzh
LANG=en_US.UTF-8
HISTCONTROL=ignoredups
SHLVL=1
HOME=/home/lzh
LOGNAME=lzh
SSH_CONNECTION=183.217.30.158 3214 192.168.15.169 22
LESSOPEN=||/usr/bin/lesspipe.sh %s
XDG_RUNTIME_DIR=/run/user/1000
HISTTIMEFORMAT=%F %T lzh 
_=/usr/bin/env
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ clear
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 ]$ cd ^H^H^H
[lzh@hcss-ecs-1552 /home/lzh]$ clear
[lzh@hcss-ecs-1552 /home/lzh]$ ll
[lzh@hcss-ecs-1552 /home/lzh]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 /home/lzh]$ echo s
s
s
[lzh@hcss-ecs-1552 /home/lzh]$ echo w
w
w
[lzh@hcss-ecs-1552 /home/lzh]$ cd^H^H
[lzh@hcss-ecs-1552 /home/lzh]$ echo $
$
$
[lzh@hcss-ecs-1552 /home/lzh]$ c^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
myshell.c: In function ‘buildcommand’:
myshell.c:121:1: error: expected declaration or statement at end of input
 }
 ^
make: *** [myshell] Error 1
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ echo sfs
sfs
[lzh@hcss-ecs-1552 ]$ echo $?
0
[lzh@hcss-ecs-1552 ]$ echo $
$
[lzh@hcss-ecs-1552 ]$ clear
[lzh@hcss-ecs-1552 ]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c
[lzh@hcss-ecs-1552 ~]$ make
gcc -o myshell myshell.c -std=c99
[lzh@hcss-ecs-1552 ~]$ ./myshell
[lzh@hcss-ecs-1552 ]$ ls
makefile  myshell  myshell.c
[lzh@hcss-ecs-1552 ]$ cd ..
[lzh@hcss-ecs-1552 /home]$ clear
[lzh@hcss-ecs-1552 /home]$ c^H
[lzh@hcss-ecs-1552 /home]$ ^C
[lzh@hcss-ecs-1552 ~]$ vim myshell.c

 1: myshell.c+  ⮀                                                                                                                                                                                   ⮂⮂ buffers 
   60     chdir(_argv[1]);//将当前工作目录修改为特定目录。修改成功返回0，出错返回-1。
   61     getpwd();//存放特定目录
   62     sprintf(getenv("PWD"), "%s", pwd);//将特定目录写入环境变量PWD中。
   63     return 1;
   64   }
   65   else if(_argc == 2 && (strcmp(_argv[0], "echo") == 0))
   66   {
   67     if (strcmp(_argv[1], "$?") == 0)
   68     {
   69       printf("%d\n", lastcode);
   70       lastcode = 0;
   71       return 1;
   72     }
   73   }
   74   if (strcmp(_argv[0], "ls") == 0)
   75   {
W> 76     _argv[_argc++] = "--color";
   77     _argv[_argc] = NULL;
   78     return 1;                                                                                                                                                                                              
   79   }
   80   return 0;
   81 }
   82 
   83 void normalexcute(char* _argv[])
   84 {
   85 
   86   pid_t id = fork();
   87   if (id < 0){
   88     return;
   89   }
   90   else if (id == 0){
   91     //子进程执行命令
   92     execvp(_argv[0], _argv);
   93     exit(EXIT_CODE);
   94   }
   95   else{
   96     //父进程进行等待
 NORMAL ⮀⮀ myshell.c[+]                                                                                                                              ⮂ buildcommand() ⮃ c   ⮂  utf-8    ⮂  60%   78/128 : 12 
                                                                                                                                                                                                        
