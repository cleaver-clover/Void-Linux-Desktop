--
-- Alias File
--

-- Save file with Ctrl+s in normal and insert mode
vim.keymap.set('n', '<C-s>', ':w<CR>', { noremap = true, silent = true })
vim.keymap.set('i', '<C-s>', '<Esc>:w<CR>', { noremap = true, silent = true })

-- needed for lazy.nvim
vim.g.mapleader = " "
vim.g.maplocalleader = "\\"
