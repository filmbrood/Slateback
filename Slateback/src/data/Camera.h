#pragma once
#include <string>
#include <vector>
#include <memory>

#include <cereal/cereal.hpp>

#include "Roll.h"

// Data class containing Camera details, which also acts as a container class for a vector of Roll object pointers.
class Camera
{
public:
	Camera() {}
	~Camera() {}

public:
	// Functions for manipulating all member variables
	void SetModel(std::string model);
	void SetFilmBack(std::string filmback);
	void SetCodec(std::string setcodec);
	void SetID(std::string id);
	void SetLensSet(std::string lenses);
	void SetCameraOperator(std::string camop);
	void SetFirstAssistantCamera(std::string firstAC);
	void SetSecondAssistantCamera(std::string secondAC);

	// Functions for retrieving member variables
	std::string GetModel();
	std::string GetFilmBack();
	std::string GetCodec();
	std::string GetID();
	std::string GetLensSet();
	std::string GetCameraOperator();
	std::string GetFirstAssistantCamera();
	std::string GetSecondAssistantCamera();

public:
	// For accessing Roll vector and data surrounding it
	void PushNewRoll();
	Roll& GetRoll(unsigned int index);

	// Returns size of m_Rolls vector
	size_t GetRollCount();

	// Sets and returns m_ActiveRollIndex
	void SetActiveRollIndex(unsigned int index);
	unsigned int GetActiveRollIndex();

	// Serializes m_Rolls using Cereal library
	template<class Archive>
	void serialize(Archive& archive);

private:

	std::string m_Model;
	std::string m_FilmBack;
	std::string m_Codec;
	std::string m_ID;
	std::string m_LensSet;
	std::string m_CameraOperator;
	std::string m_FirstAssistantCamera;
	std::string m_SecondAssistantCamera;

	unsigned int m_ActiveRollIndex = 0;

	std::vector<Roll> m_Rolls;
};

template<class Archive>
inline void Camera::serialize(Archive& archive)
{
	archive(CEREAL_NVP(m_ActiveRollIndex), CEREAL_NVP(m_Rolls), CEREAL_NVP(m_Model), CEREAL_NVP(m_FilmBack), CEREAL_NVP(m_Codec), CEREAL_NVP(m_ID), CEREAL_NVP(m_LensSet), CEREAL_NVP(m_CameraOperator), CEREAL_NVP(m_FirstAssistantCamera), CEREAL_NVP(m_SecondAssistantCamera));
}
