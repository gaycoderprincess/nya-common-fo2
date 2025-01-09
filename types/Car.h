class Gearbox {
public:
	uint8_t _0[0x40];
	uint8_t nGear;
	uint8_t _41[0x83];
};

class Suspension {
public:
	float fBumpDamp; // +0
	float fReboundDamp; // +4
	uint8_t _8[0x24];
	float fHealth; // +2C
	uint8_t _30[0x10];
};

class tTextureNode {
public:
	DevTexture* pTexture;
};

class Player;
class Car {
public:
	uint8_t _0[0x1B0];
	float mMatrix[4*4]; // +1B0
	uint8_t _1F0[0x80];
	float qQuaternion[4]; // +270
	float vVelocity[3]; // +280
	uint8_t _28C[0x4];
	float vAngVelocity[3]; // +290
	uint8_t _29C[0x4];
	float vVelocityGravity[3]; // +2A0
	uint8_t _2AC[0x320];
	float fNitro; // +5CC
	float fMaxNitro; // +5D0
	uint8_t _5D4[0x20];
	Gearbox mGearbox; // +5F4
	uint8_t _6B8[0x11D8];
	Suspension aSuspension[4]; // +1890
	uint8_t _1990[0x28C];
	tTextureNode** pTextureNodes; // +1C1C
	tTextureNode** pTextureNodesEnd; // +1C20
	uint8_t _1C24[0x28];
	float fMass; // +1C4C
	uint8_t _1C50[0x50];
	uint32_t nHandsId; // +1CA0
	uint8_t _1CA4[0x18];
	float vCenterOfDownforce[3]; // +1CBC
	uint8_t _1CC8[0x38];
	float fDownforceConst; // +1D00
	uint8_t _1D04[0x34];
	float fSuspensionFrontBumpDamp; // +1D38
	float fSuspensionFrontReboundDamp; // +1D3C
	uint8_t _1D40[0x3C];
	float fSuspensionRearBumpDamp; // +1D7C
	float fSuspensionRearReboundDamp; // +1D80
	uint8_t _1D84[0x70];
	float fGasPedal; // +1DF4
	float fBrakePedal; // +1DF8
	float fNitroButton; // +1DFC
	float fHandbrake; // +1E00
	float fSteerAngle; // +1E04
	uint8_t _1E08[0xC88];
	uint32_t _driverStruct; // +2A90
	uint8_t _2A94[0x1B00];
	DevTexture* pSkinDamaged; // +4594
	DevTexture* pLightsDamaged; // +4598
	DevTexture* pLightsGlow; // +459C
	DevTexture* pLightsGlowLit; // +45A0
	uint8_t _45A4[0x98];
	Player* pPlayer; // +463C
	uint8_t _4640[0x2460];
	float fDamage; // +6AA0

#ifdef NYA_MATH_H
	inline NyaMat4x4* GetMatrix() {
		return (NyaMat4x4*)mMatrix;
	}
	inline NyaVec3* GetVelocity() {
		return (NyaVec3*)vVelocity;
	}
	inline NyaVec3* GetAngVelocity() {
		return (NyaVec3*)vAngVelocity;
	}
#endif
};