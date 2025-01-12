return require('packer').startup(function(use)
    use 'wbthomason/packer.nvim'

    -- Autopairs
    use 'jiangmiao/nvim-autopairs'

    -- Nvim tree
    use 'nvim-tree/nvim-tree.lua'
    use 'nvim-tree/nvim-web-devicons'

    --Coc
    use {
        'neoclide/coc.nvim',
        branch = 'release'
    }
end)
