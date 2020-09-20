#pragma once
#include <string>

class Camera
{
public:
	void SetModel(std::string model);
	void SetFilmBack(std::string filmback);
	void SetCodec(std::string setcodec);
	void SetID(std::string id);
	void SetLensSet(std::string lenses);

	std::string GetModel();
	std::string GetFilmBack();
	std::string GetCodec();
	std::string GetID();
	std::string GetLensSet();

	void CameraSetup();
	void PrintCameraDetails();

private:
	std::string m_Model;
	std::string m_FilmBack;
	std::string m_Codec;
	std::string m_ID;
	std::string m_LensSet;

	std::string CameraSetupDetail(std::string detail);
};