#include <codecvt>

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

struct tFontBak {
	NyaDrawing::CNyaRGBA32 nColor;
	bool bXCenterAlign : 1;
	bool bXRightAlign : 1;
	float fScaleX;
	float fScaleY;
};

void DrawStringFO2(tNyaStringData data, const wchar_t* string, const char* font) {
	auto pFont = Font::GetFont(*(void **) (0x8E8434), font);

	tFontBak bak;
	bak.fScaleX = pFont->fScaleX;
	bak.fScaleY = pFont->fScaleY;
	bak.nColor = pFont->nColor;
	bak.bXCenterAlign = pFont->bXCenterAlign;
	bak.bXRightAlign = pFont->bXRightAlign;

	pFont->fScaleX = data.size * nResX / 20.0;
	pFont->fScaleY = data.size * nResY / 20.0;
	pFont->bXRightAlign = data.XRightAlign;
	pFont->bXCenterAlign = data.XCenterAlign;
	pFont->nColor.r = data.b;
	pFont->nColor.g = data.g;
	pFont->nColor.b = data.r;
	pFont->nColor.a = data.a;
	pFont->fScaleX *= GetAspectRatioInv();
	Font::Display(pFont, data.x * nResX, data.y * nResY, string);

	pFont->fScaleX = bak.fScaleX;
	pFont->fScaleY = bak.fScaleY;
	pFont->nColor = bak.nColor;
	pFont->bXCenterAlign = bak.bXCenterAlign;
	pFont->bXRightAlign = bak.bXRightAlign;
}

void DrawStringFO2(const tNyaStringData& data, const std::string& name) {
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	DrawStringFO2(data, converter.from_bytes(name).c_str(), "FontLarge");
}