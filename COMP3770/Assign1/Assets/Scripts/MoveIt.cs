using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveIt : MonoBehaviour
{   
    public float speed = 1;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

    }

    private void FixedUpdate() {
        // Check if the x value is at the max or min value
        if(gameObject.transform.position.x >= 3 || gameObject.transform.position.x <= -3){
            // Change the direction
            speed = speed * -1;
        }
        // Move the object based the current direction and time
        gameObject.transform.Translate(speed * Time.fixedDeltaTime, 0, 0);
    }
}
