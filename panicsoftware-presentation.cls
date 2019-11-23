\ProvidesClass{panicsoftware-presentation}[Dawid's style of presentations]
\LoadClass[10pt]{beamer}

\usetheme[progressbar=frametitle, block=fill]{metropolis}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[english]{babel}
\usepackage[scale=2]{ccicons}
\usepackage{minted}
\newcommand{\cmark}{\ding{51}}
\newcommand{\xmark}{\ding{55}}


\definecolor{amethyst}{rgb}{0.5, 0.4, 1.0}
\definecolor{amethystgrey}{rgb}{0.85, 0.85, 1.0}
\definecolor{amethystdark}{rgb}{0.4, 0.3, 0.9}
\definecolor{titlebg}{HTML}{fbf8ff}
\definecolor{background}{HTML}{fafafa}
\definecolor{font}{HTML}{23373b}

\setbeamercolor{frametitle}{fg= font, bg=titlebg}
\setbeamercolor{progress bar}{ fg = amethyst, bg= amethystgrey }
\setbeamercolor{alerted text}{fg=amethystdark}

\def \myCpp {coroLexer.py -x}
\def \codeTilda {\raise.17ex\hbox{$\scriptstyle\mathtt{\sim}$}}

\newcommand{\mylogo}[1]{\addtobeamertemplate{frametitle}{}{%
\begin{textblock*}{100mm}(1\textwidth, -1cm)
\includegraphics[height=0.97cm]{#1}
\end{textblock*}}}

\institute{dawid.pilarski@panicsoftware.com \\ \href{http://blog.panicsoftware.com}{blog.panicsoftware.com} \\ dawid.pilarski@tomtom.com}