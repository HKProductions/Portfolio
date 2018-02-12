using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class EncounterInstance : MonoBehaviour 
{
	public LocationList Cave;
	GameObject player;
	private EventManager eMan;
	[SerializeField] float comChance, uncomChance, epicChance, encoChance;
	[SerializeField] bool bossStage;
	// Use this for initialization
	void Start()
	{
		eMan = GameObject.FindGameObjectWithTag("EventManager").GetComponent<EventManager>(); //event manager called
		player = GameObject.FindGameObjectWithTag("Player");
	}
		
	// Update is called once per frame
	void Update() 
	{
		
	}

	//allows for a trigger to randomly encounter enemies
	void OnTriggerEnter2D(Collider2D col)
	{
		if (col.GetComponent<PlayerMove>())  //if moving in a tile that can encounter an enemy
		{			
			comChance = 10.0f / 150.0f;
			uncomChance = 6.0f / 150.0f; 
			epicChance = 2.5f / 150.0f;

			encoChance = Random.Range(0.0f, 100.0f);
			if (encoChance < epicChance * 100)
			{
				//if event manage is active and states the chance of encountering
				if (eMan != null)
				{
					eMan.BattleStart (RandomEncounter.Epic); 
				}
			}
			else if (encoChance < uncomChance * 100)
			{
				//if event manage is active and states the chance of encountering
				if (eMan != null)
				{
					eMan.BattleStart (RandomEncounter.Uncommon);
				}
			}
			else if (encoChance < comChance * 100)
			{
				//if event manage is active and states the chance of encountering
				if (eMan != null)
				{
					eMan.BattleStart (RandomEncounter.Common);
				}
			}
		}
	}

	public bool BossStage 
	{
		get{ return bossStage; }
		set{ bossStage = value; }
	}

}
