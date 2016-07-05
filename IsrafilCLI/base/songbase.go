package base

const (
	SrcNetease = 1
	SrcQQMusic = 2
	SrcXiami   = 3
	SrcKuwo    = 4
)

//Musician defines universal Author struct
type Musician struct {
	MName     string
	MID       string
	MURL      string
	MSongnum  uint
	MAlbumnum uint
	MPicURL   string
}

//Album defines universal album structure
type Album struct {
	AName   string
	AID     string
	APicURL string
	AURL    string
}

//Lyrics defines universal lyrics URL (Deprecated)
type Lyrics struct {
	LURL string
}

//Song defines the main structure of universal song apis
type Song struct {
	SName           string
	SID             string
	UID             string
	SSingers        []Musician
	SAlbum          Album
	SSource         uint
	SOnly           bool
	SMp3URLs        []string
	SLLURLs         []string
	SPicURLs        []string
	SLyricsURLs     []string
	SURL            string
	SDevString      string
	SSlot1          string
	SSlot2          string
	SIsMp3Filled    bool
	SIsLyricsFilled bool
	SIsPicFilled    bool
	SIsAlbumFilled  bool
}

//SearchRet SR
type SearchRet struct {
	NumOfRes uint
	Songs    []Song
}

func NewSong() *Song {
	p := new(Song)
	p.SIsAlbumFilled = false
	p.SIsLyricsFilled = false
	p.SIsMp3Filled = false
	p.SIsPicFilled = false
	return p
}
