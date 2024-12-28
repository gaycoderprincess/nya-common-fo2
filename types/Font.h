class Font {
public:
	uint8_t _0[0x4];
	NyaDrawing::CNyaRGBA32 nColor;
	uint8_t _8[0x2C];
	struct {
		bool bXCenterAlign : 1;
		bool bXRightAlign : 1;
	};
	uint8_t _38[0x14];
	float fScaleX;
	float fScaleY;

	static inline auto GetFont = (Font*(__stdcall*)(void*, const char*))0x451840;
	static inline auto Display = (void(*)(Font*, float, float, const wchar_t*, ...))0x54E820;
};

void DrawStringFO2(tNyaStringData data, const wchar_t* string, const char* font) {
	auto pFont = Font::GetFont(*(void**)(0x8E8434), font);
	pFont->fScaleX = data.size * nResX / 20.0;
	pFont->fScaleY = data.size * nResY / 20.0;
	pFont->bXRightAlign = data.XRightAlign;
	pFont->bXCenterAlign = data.XCenterAlign;
	pFont->nColor.r = data.r;
	pFont->nColor.g = data.g;
	pFont->nColor.b = data.b;
	pFont->nColor.a = data.a;
	pFont->fScaleX *= GetAspectRatioInv();
	Font::Display(pFont, data.x * nResX, data.y * nResY, string);
}