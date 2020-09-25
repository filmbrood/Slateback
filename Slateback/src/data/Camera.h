#pragma once
#include <string>
#include <vector>
#include <memory>

#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

#include "Roll.h"

// Data class containing Camera details, which also acts as a container class for a vector of Roll object pointers.
class Camera
{
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
	Roll GetRoll(unsigned int index);

	// Returns size of m_Rolls vector
	size_t GetRollCount();

	// Serializes m_Rolls using Cereal library
	template<class Archive>
	void serialize(Archive& archive)
	{
		archive(m_Rolls, m_Model, m_FilmBack, m_Codec, m_ID, m_LensSet, m_CameraOperator, m_FirstAssistantCamera, m_SecondAssistantCamera);
	}

private:

	std::string m_Model;
	std::string m_FilmBack;
	std::string m_Codec;
	std::string m_ID;
	std::string m_LensSet;
	std::string m_CameraOperator;
	std::string m_FirstAssistantCamera;
	std::string m_SecondAssistantCamera;

	std::vector<Roll> m_Rolls;
};