using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cube : MonoBehaviour
{
    public float speed = 5;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        gameObject.transform.Translate(0, speed, 0);
    }

    // FixedUpdate is called once every fixed frame timer
    void FixedUpdate(){
        speed += Time.fixedDeltaTime / 1030;
    }
}
