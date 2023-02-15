using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ResizeIt : MonoBehaviour
{
    private Vector3 changeScale = new Vector3(1, 1, 1);
    private Vector3 max = new Vector3(4, 4, 4);
    private Vector3 min = new Vector3(1, 1, 1);
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void FixedUpdate() {
        // Change scale once per second
        gameObject.transform.localScale += changeScale * Time.fixedDeltaTime;
        // If max or min size
        if(gameObject.transform.localScale == max || gameObject.transform.localScale == min){
            // Reverse direction of scale change
            changeScale = changeScale * -1;
        }
    }
}
