using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerInfo : MonoBehaviour 
{
	public List<GameObject> allParty = new List<GameObject>(); //list of the players party

	// Use this for initialization
	void Start() 
	{
		
	}
	
	// Update is called once per frame
	void Update() 
	{
		
	}

	public void RemoveParty(GameObject partyMember)
	{
		allParty.Remove(partyMember);
	}
}

//players party and skills they have not sure if this will be used
//[System.Serializable]
public class PlayerParty
{
	public Entity character; //the characters that are in the party
	public List<SkillsComponent> skills = new List<SkillsComponent>(); //the skills that the party has
}