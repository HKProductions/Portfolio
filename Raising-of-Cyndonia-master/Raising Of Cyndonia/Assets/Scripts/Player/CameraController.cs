using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour 
{
	private GameObject player;
	private Vector3 offset;

	//sets camera to follow the player during exploration
	void Awake()
	{
		player = GameObject.FindWithTag("Player");
		offset = gameObject.transform.position - player.transform.position;
	}


	// Use this for initialization


	void Start() 
	{
		
	}
	
	// Update is called once per frame
	void Update() 
	{
		gameObject.transform.position = player.transform.position + offset;
	}
}
