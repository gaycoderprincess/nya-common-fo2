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

class Player;
class Car {
public:
	uint8_t _0[0x1B0];
	float mMatrix[4*4];			// +1B0
	uint8_t _1F0[0x80];
	float qQuaternion[4];		// +270
	float vVelocity[3];			// +280
	uint8_t _28C[0x4];
	float vAngVelocity[3];		// +290
	uint8_t _29C[0x330];
	float fNitro;				// +5CC
	uint8_t _5D0[0x24];
	Gearbox mGearbox;			// +5F4
	uint8_t _6B8[0x11D8];
	Suspension aSuspension[4]; // +1890
	uint8_t _1990[0x3A8];
	float fSuspensionFrontBumpDamp; // +1D38
	float fSuspensionFrontReboundDamp; // +1D3C
	uint8_t _1D40[0x3C];
	float fSuspensionRearBumpDamp; // +1D7C
	float fSuspensionRearReboundDamp; // +1D80
	uint8_t _1D84[0x70];
	float fGasPedal;			// +1DF4
	float fBrakePedal;			// +1DF8
	float fNitroButton;			// +1DFC
	float fHandbrake;			// +1E00
	float fSteerAngle;			// +1E04
	uint8_t _1E08[0x4C98];
	float fDamage;				// +6AA0

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