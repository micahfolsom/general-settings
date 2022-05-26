"" Micah's basic vim settings
"" vim-plug (https://github.com/junegunn/vim-plug)
"" Automatically install vim-plug
if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
endif
" Run PlugInstall if there are missing plugins
autocmd VimEnter * if len(filter(values(g:plugs),'!isdirectory(v:val.dir)'))
  \| PlugInstall --sync | source $MYVIMRC
\| endif

"" Plugins
call plug#begin('~/.vim/plugged')
Plug 'jam1garner/vim-code-monokai'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
" For this one, you need to go into ~/.vim/plugged and run
" `python install.py --all` to set this up the first time
Plug 'Valloric/YouCompleteMe'
call plug#end()

"" Colors
colorscheme molokai
let g:airline_theme = 'codedark'
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

"" Termdebug, put gdb/output side-by-side with code
packadd termdebug
let g:termdebug_wide=1
let g:termdebug_wide=165

"" YCM settings
" Make YCM cursor-hover popups faster [ms]
set updatetime=2000
" Turn off that annoying prompt
let g:ycm_confirm_extra_conf=0
" Fix error background highlighting to be less offensive
let g:ycm_enable_diagnostic_signs=1
highlight YcmErrorSection ctermbg=0
" Don't open split window preview
set completeopt-=preview

" clang-format mappings (too low version?)
"map <C-K> :pyf ~/.vim/clang-format.py<cr>
"imap <C-K> <c-o>:pyf ~/.vim/clang-format.py<cr>

" Just can't let go of the shift key, can you?
:command W w
:command Q q
:command Wq wq
:command WQ wq
" I use this a lot
:command NN set nonumber
