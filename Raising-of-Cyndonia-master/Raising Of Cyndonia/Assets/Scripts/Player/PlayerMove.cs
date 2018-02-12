using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour 
{

	Direction curDir; //current direction
	Vector2 input; //input of the user
	bool isMoving = false; //sets player moving as false
	public bool inCombat = false;
	Vector3 sPos, ePos; //start position and end position
	float time; //time value

	//allows for setting of the north, east, south, west sprites
	public Sprite nSprite;
	public Sprite eSprite;
	public Sprite sSprite;
	public Sprite wSprite;

	public float speed = 0.1f; //speed of grid transition

	void Start()
	{
		inCombat = false; //not in combat will allow movement
	}
	
	// Update is called once per frame
	void Update() 
	{
		if (Input.GetKey(KeyCode.Escape))
		{
			Application.Quit();
		}
		if (!isMoving && !inCombat) 
		{
			//gets the wasd keys and such to allow player to move
			input = new Vector2 (Input.GetAxis("Horizontal"), Input.GetAxis("Vertical"));

			//allows for grid movement
			if (Mathf.Abs(input.x) > Mathf.Abs(input.y)) 
			{
				input.y = 0;
			} 
			else 
			{
				input.x = 0;
			}

			//used for calling sprites based off of direction
			if (input != Vector2.zero)
			{
				if (input.x < 0)
				{
					curDir = Direction.W; //west
				}
				if (input.x > 0)
				{
					curDir = Direction.E; //east
				}
				if (input.y < 0)
				{
					curDir = Direction.S; //south
				}
				if (input.y > 0)
				{
					curDir = Direction.N; //north
				}

				//uses switch statement to get the sprites
				switch (curDir)
				{
					case Direction.N:
						gameObject.GetComponent<SpriteRenderer>().sprite = nSprite; //north face sprite
						break;
					case Direction.E:
						gameObject.GetComponent<SpriteRenderer>().sprite = eSprite; //east face sprite
						break;
					case Direction.S:
						gameObject.GetComponent<SpriteRenderer>().sprite = sSprite; //south face sprite
						break;
					case Direction.W:
						gameObject.GetComponent<SpriteRenderer>().sprite = wSprite; //west face sprite
						break;
				}

				//starts coroutine for player to move based off of a grid
				StartCoroutine(MoveP(transform));
			}
		}
	}

	//movement of the player
	public IEnumerator MoveP(Transform player)
	{
		isMoving = true; //sets player moving to true
		sPos = player.position; //gets players position as the start position
		time = 0; //sets time to 0

		//gets the end position based off of the grid and input
		ePos = new Vector3(sPos.x + System.Math.Sign(input.x), sPos.y + System.Math.Sign(input.y), sPos.z);

		//while time is less than 1 then it will move the player
		while (time < 1f)
		{
			time += Time.deltaTime + speed;
			player.position = Vector3.Lerp(sPos, ePos, time); //sets players position to next grid tile
			yield return null;
		}

		isMoving = false; //sets move as false
		yield return 0;
	}

}

//directions player has to move and face
enum Direction
{
	N, E, S, W //goes North, East, South, West accordingly
}