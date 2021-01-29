"" Micah's basic vim settings
" Colors
colorscheme molokai
set t_Co=256
" lol OSX
syntax on
" Spaces only; indentation and numbering
set expandtab
set shiftwidth=2
set softtabstop=2
set autoindent
set smartindent
set number
" Make it so ie. /* continues with a * on the next line
filetype plugin indent on
" Prevent // from continuing
au FileType c,cpp setlocal comments-=:// comments+=f://
