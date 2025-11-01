return {
    {
        "lewis6991/gitsigns.nvim",
        config = function()
            require("gitsigns").setup()
        end,
    },
    {
        "OXY2DEV/markview.nvim",
    },
    {
        "folke/zen-mode.nvim",
        opts = {
            -- your configuration comes here
            -- or leave it empty to use the default settings
            -- refer to the configuration section below
        }
    },
    {
        "preservim/vim-pencil",
        init = function()
            vim.g["pencil#wrapModeDefault"] = "soft"
        end,
    },
}
