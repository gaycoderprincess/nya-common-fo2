class Application {
public:

	virtual void _dtor() = 0;
	virtual void WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) = 0;
	virtual void MessageHandler(int shouldBlock) = 0;
};
auto& pApplication = *(Application**)0x8DA71C;