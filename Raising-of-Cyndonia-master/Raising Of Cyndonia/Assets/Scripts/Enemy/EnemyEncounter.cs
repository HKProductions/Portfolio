using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EnemyEncounter : MonoBehaviour 
{
	public string name;
	public Sprite image;
	public LocationList locationIn; //location you are in
	public RandomEncounter encountChance; //the chance you will encounter
	Entity entInfo; //entity's stats

	// Use this for initialization
	void Start() 
	{
		
	}
	
	// Update is called once per frame
	void Update()
	{
		
	}
}

//the chance you will encounter an enemy
public enum RandomEncounter
{
	Common, Uncommon, Epic
}

public enum Enemies
{
	
}