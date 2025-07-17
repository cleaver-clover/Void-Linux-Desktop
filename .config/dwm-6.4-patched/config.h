/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;       	/* border pixel of windows */
static const unsigned int gappih    = 6;       	/* horiz inner gap between windows (used to set gaps in column layout)*/
static const unsigned int gappiv    = 6;       	/* vert inner gap between windows */
static const unsigned int gappoh    = 6;       	/* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;       	/* vert outer gap between windows and screen edge */
static int smartgaps          	    = 0;       	/* 1 means no outer gap when there is only one window */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int minwsz    = 20;       /* Minimal heigt of a client for smfact */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 22;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 6;       	/* vertical padding of bar */
static const int sidepad            = 6;       	/* horizontal padding of bar */
static const char *fonts[]          = { "JetBrainsMono:size=10" };
static const char dmenufont[]       = "JetBrainsMono:size=10";


static char normbgcolor[]           = "#212529";
static char normbordercolor[]       = "#6C757D";
static char normfgcolor[]           = "#DEE2E6";
static char selfgcolor[]            = "#DEE2E6";
static char selbordercolor[]        = "#DEE2E6"; 
static char selbgcolor[]            = "#533A22"; 
static char *colors[][3] = { 
//	                 fg           bg           border   
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor }, 
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

// Auto Start
// Shell command start with: "sh", "-c",
static const char *const autostart[] = {

	/* dwm bar with xsetroot*/
	"sh", "-c", "~/.config/scripts/dwm-bar.sh", NULL,

	/* Batery alarm on laptop */
	//"sh", "-c", "~/.config/scripts/battery-level.sh", NULL,

	/* Notification */
	"dunstify","Hello World!!!", NULL,

	NULL /* Terminate */
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     	NULL,       NULL,       0,            0,           0 },
	{ "keepassxc",  NULL,       NULL,       0,            0,           9 },
	{ "nemo",  		NULL,       NULL,       0,            0,           8 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const float smfact    = 0.00; /* factor of tiled clients [0.00..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */

static const Layout layouts[] = {
	/* symbol     	arrange function */
	{ "MS",      	tile },    /* first entry is default */
	{ "CentM",      centeredmaster },
	{ "Float",      NULL },    /* no layout function means floating behavior */
	{ "BotS",      	bstack },
	{ "Grid",      	grid },
	{ "nrGrid",     nrowgrid },
	{ "BotHS",      bstackhoriz },
//	{ "CentFM",     centeredfloatingmaster },
//	{ "Mon",      	monocle },

};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
	{ MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
	{ MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \
	{ MOD, XK_F1,     ACTION##stack, {.i = 0 } }, \
	{ MOD, XK_F2,     ACTION##stack, {.i = 1 } }, \
	{ MOD, XK_F3,     ACTION##stack, {.i = 2 } }, \
	{ MOD, XK_F4,     ACTION##stack, {.i = -1 } },
 
/* grave key: ' symbol*/ 

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *termcmd[] = { "kitty", NULL };

// xev is a utility that can name the keys as you press them
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,						XK_Return, spawn,			{.v = termcmd } },
	{ MODKEY,						XK_space,  spawn,			SHCMD("rofi -show drun") },
	{ MODKEY,						XK_Escape, spawn,			SHCMD(" ~/.config/scripts/rofi-powermenu.sh") },
	{ MODKEY,						XK_w, 	   spawn,			SHCMD("~/.config/scripts/nsxiv.sh") },
	{ MODKEY,						XK_p, 	   spawn,			SHCMD("flameshot gui") },
	{ 0,							XK_Print,  spawn,           SHCMD("flameshot gui") },
	{ MODKEY|Mod1Mask,				XK_b, 	   spawn,           SHCMD("firefox") },
	{ MODKEY|Mod1Mask,				XK_l, 	   spawn,           SHCMD("logseq") },
	{ MODKEY|Mod1Mask,				XK_k, 	   spawn,           SHCMD("keepassxc") },
	{ MODKEY|Mod1Mask,				XK_n, 	   spawn,           SHCMD("nemo") },
 	{ MODKEY,						XK_b,      togglebar,       {0} },	
	{ MODKEY,						XK_plus,   incnmaster,      {.i = +1 } },
	{ MODKEY,						XK_minus,  incnmaster,      {.i = -1 } },
	{ MODKEY,						XK_h,      setmfact,        {.f = -0.05} },
	{ MODKEY,						XK_l,      setmfact,        {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setsmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setsmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_z, 	   zoom,            {0} },
	{ MODKEY,                       XK_Tab,    view,            {0} },
	{ MODKEY,             		    XK_q,      killclient,      {0} },
	{ ControlMask,           		XK_1,      setlayout,       {.v = &layouts[0]} },
	{ ControlMask,           		XK_2,      setlayout,       {.v = &layouts[1]} },
	{ ControlMask,           		XK_3,      setlayout,       {.v = &layouts[2]} },
	{ ControlMask,           		XK_4,      setlayout,       {.v = &layouts[3]} },
	{ ControlMask,           		XK_5,      setlayout,       {.v = &layouts[4]} },
	{ ControlMask,          		XK_6,      setlayout,       {.v = &layouts[5]} },
	{ ControlMask,          		XK_7,      setlayout,       {.v = &layouts[6]} },
//	{ ControlMask,           		XK_8,      setlayout,       {.v = &layouts[7]} },
//	{ ControlMask,              	XK_9,      setlayout,       {.v = &layouts[8]} },
//	{ ControlMask,           		XK_space,  setlayout,       {0} },
	{ MODKEY,             			XK_s,  	   togglefloating,  {0} },
	{ MODKEY,             			XK_f,      togglefullscr,   {0} },
	{ MODKEY,                       XK_Down,   moveresize,      {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,      {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,      {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,      {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,      {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,      {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,      {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,      {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge,  {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge,  {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge,  {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge,  {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge,  {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge,  {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge,  {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge,  {.v = "R"} },
	{ MODKEY,                       XK_0,      view,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,             {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,        {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,        {.i = +1 } },
	{ MODKEY,           			XK_Next,   viewnext,   	    {0} },
	{ MODKEY,           			XK_Prior,  viewprev,        {0} },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,          {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,          {.i = +1 } },
	{ MODKEY,                       XK_r,      spawn,           SHCMD("~/.config/scripts/set-rand-wallpaper.sh") },
	{ MODKEY|ControlMask,       	XK_Prior,  spawn,           SHCMD("pamixer -u -i 2") },
	{ MODKEY|ControlMask,       	XK_Next,   spawn,           SHCMD("pamixer -u -d 2") },
	{ MODKEY|ControlMask,       	XK_m,      spawn,           SHCMD("pamixer -t") },
	{ 0,							0x1008ff13,spawn,           SHCMD("pamixer -u -i 2") },
	{ 0,							0x1008ff11,spawn,           SHCMD("pamixer -u -d 2") },
	{ 0,							0x1008ff12,spawn,           SHCMD("pamixer -t") },
	{ ControlMask,       	    	XK_Down,   spawn,           SHCMD("playerctl play-pause") },
	{ ControlMask,       	    	XK_Right,  spawn,           SHCMD("playerctl next") },
	{ ControlMask,       	    	XK_Left,   spawn,			SHCMD("playerctl previous") },
	{ ShiftMask,       	    		XK_Down,   spawn,           SHCMD("mpc toggle") },
	{ ShiftMask,       	    		XK_Right,  spawn,           SHCMD("mpc next") },
	{ ShiftMask,       	    		XK_Left,   spawn,			SHCMD("mpc prev") },
	{ MODKEY|ShiftMask,				XK_Next,   spawn,			SHCMD("brightnessctl set 5%+") },
	{ MODKEY|ShiftMask,				XK_Prior,  spawn,          	SHCMD("brightnessctl set 5%-") },
	{ 0,							0x1008ff03,spawn,           SHCMD("brightnessctl set 5%+") },
	{ 0,							0x1008ff03,spawn,           SHCMD("brightnessctl set 5%-") },
	/* Rotate screen on 180 degrees laptops */
	{ ShiftMask,					0x1008ff74,spawn,   	    SHCMD("xrandr --output eDP --primary --mode 1920x1080 --rate 60 --rotate normal") },
	{ 0,							0x1008ff74,spawn,   	    SHCMD("xrandr --output eDP --primary --mode 1920x1080 --rate 60 --rotate inverted") },
	/* Enables HDMI and stuff on laptops */
	{ 0,							0x1008ff41,spawn,           SHCMD("xrandr --output eDP --primary --mode 1920x1080 --pos 0x0 --rotate normal --output HDMI-A-0 --mode 1920x1080 --pos 1920x0 --rotate normal --output DisplayPort-0 --off --output DisplayPort-1 --off") },
  	{ ShiftMask,					0x1008ff41,spawn,           SHCMD("xrandr --output eDP --primary --mode 1920x1080 --pos 0x0 --rotate normal --output HDMI-A-0 --off --output DisplayPort-0 --off --output DisplayPort-1 --off") },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	TAGKEYS(                        XK_7,                       6)
	TAGKEYS(                        XK_8,                       7)
	TAGKEYS(                        XK_9,                       8)
	STACKKEYS(MODKEY,            	focus)
	STACKKEYS(MODKEY|ShiftMask,     push)
	{ MODKEY|ShiftMask,				XK_BackSpace,      			quit,   			{0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

void
setlayoutex(const Arg *arg)
{
	setlayout(&((Arg) { .v = &layouts[arg->i] }));
}

void
viewex(const Arg *arg)
{
	view(&((Arg) { .ui = 1 << arg->ui }));
}

void
viewall(const Arg *arg)
{
	view(&((Arg){.ui = ~0}));
}

void
toggleviewex(const Arg *arg)
{
	toggleview(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagex(const Arg *arg)
{
	tag(&((Arg) { .ui = 1 << arg->ui }));
}

void
toggletagex(const Arg *arg)
{
	toggletag(&((Arg) { .ui = 1 << arg->ui }));
}

void
tagall(const Arg *arg)
{
	tag(&((Arg){.ui = ~0}));
}

void
reloadxrdb(const Arg *arg)
{
	xrdb(NULL);
}

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum           function */
	{ "focusstack",     focusstack },
	{ "setmfact",       setmfact },
	{ "togglebar",      togglebar },
	{ "incnmaster",     incnmaster },
	{ "togglefloating", togglefloating },
	{ "focusmon",       focusmon },
	{ "tagmon",         tagmon },
	{ "zoom",           zoom },
	{ "view",           view },
	{ "viewall",        viewall },
	{ "viewex",         viewex },
	{ "toggleview",     view },
	{ "toggleviewex",   toggleviewex },
	{ "tag",            tag },
	{ "tagall",         tagall },
	{ "tagex",          tagex },
	{ "toggletag",      tag },
	{ "toggletagex",    toggletagex },
	{ "killclient",     killclient },
	{ "quit",           quit },
	{ "setlayout",      setlayout },
	{ "setlayoutex",    setlayoutex },
	{ "reloadxrdb",	    reloadxrdb },
};
