local vim

vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.autoindent = true
vim.opt.smartindent = true
vim.opt.expandtab = true
vim.opt.tabstop = 4
vim.opt.shiftwidth = 4

vim.api.nvim_set_keymap('v', '<C-c>', [[:w !clip.exe<CR><CR>]], { noremap = true, silent = true })
vim.api.nvim_set_keymap('n', '<C-y>', [[:%w !clip.exe<CR><CR>]], { noremap = true, silent = true })

vim.g.coc_node_path = '/home/jay17/.nvm/versions/node/v23.6.0/bin/node'