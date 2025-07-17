// made by https://github.com/khuedoan/slock
/* user and group to drop privileges to */
static const char *user  = "clover";
static const char *group = "clover";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#000000",   /* after initialization */
	[INPUT] =  "#5f687a",   /* during input */
	[FAILED] = "#ca4336",   /* wrong password */
};

/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		{ "color0",		STRING,  	&colorname[INIT] },		/* after initialization */
		{ "color4",		STRING,  	&colorname[INPUT] },	/* during input */
		{ "color2",		STRING,  	&colorname[FAILED] }, 	/* wrong password */
};

/* lock screen opacity */
static const float alpha = 0.9;

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* default message */
static const char * message = "(^-^)";

/* text color */
static const char * text_color = "color0";

/* text size (must be a valid size) */
static const char * text_size = "fixed";
