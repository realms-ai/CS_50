<?

    /***********************************************************************
     * dictionary.php
     *
     * Computer Science 50
     * David J. Malan
     *
     * Implements a dictionary.
     **********************************************************************/


    // size of dictionary
    $size = 0;

    // dictionary
    $dictionary = array();


    /*
     * bool
     * check($word)
     *
     * Returns true if word is in dictionary else false.
     */

    function check($word)
    {
        global $dictionary;
        if ($dictionary[strtolower($word)])
            return true;
        else
            return false;
    }


    /*
     * bool
     * load($dict)
     *
     * Loads dict into memory.  Returns true if successful else false.
     */

    function load($dict)
    {
        global $dictionary, $size;
        if (!file_exists($dict) && is_readable($dict))
            return false;
        foreach (file($dict) as $word)
        {
            $dictionary[chop($word)] = true;
            $size++;
        }
        return true;
    }


    /*
     * int
     * size()
     *
     * Returns number of words in dictionary if loaded else 0 if not yet loaded.
     */

    function size()
    {
        global $size;
        return $size;
    }


    /*
     * int
     * unload()
     *
     * Unloads dictionary from memory.  Returns true if successful else false.
     */

    function unload()
    {
        return true;
    }

?>
