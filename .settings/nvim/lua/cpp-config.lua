local vim

-- Compile C++ code
vim.cmd('autocmd fyletype cpp nnoremap <F9> :w <bar> :!g++ -std=c++17 % -o %:r<CR>')

-- Run
vim.cmd('autocmd fyletype cpp nnoremap <F10> :vsp <CR> :term ./%:r<CR>')