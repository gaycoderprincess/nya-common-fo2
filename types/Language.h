class Language {
public:
	uint32_t nNumPhrases;
	struct {
		const wchar_t* sString;
		uint32_t nLength;
	} aPhrases[1];
};
auto& pLanguage = *(Language**)0x8DA574;