<?php // vim: et
/* The format is:
 * array(
 *     "major release number" => array(
 *         "release" => array(
 *             "source/windows" => array(
 *                 "filename" => "filename.tar.bz2",
 *                 "name"     => "package name",
 *                 "sha256"   => "shasum -256",
 *                 "date"     => "this files release date",
 *                 "note"     => "this file was updated 29feb due to broken phar files..",
 *             ),
 *             "announcement" => "bool, release announcement exists in releases/?",
 *         ),
 *     ),
 * );
 */
$RELEASES = (function() {
    /* PHP 7.4 Release */
    $PHP_7_4_VERSION         = "7.4.1";
    $PHP_7_4_DATE            = "18 Dec 2019";
    $PHP_7_4_TAGS            = []; // Set to ['security'] for security releases.
    $PHP_7_4_SHA256     = array(
        "tar.gz"        => "67265d6bd48d828f4725964f71ca5c76c3da63b0d07bec5ec4e5acfdd3708073",
        "tar.bz2"       => "6b1ca0f0b83aa2103f1e454739665e1b2802b90b3137fc79ccaa8c242ae48e4e",
        "tar.xz"        => "561bb866bdd509094be00f4ece7c3543ec971c4d878645ee81437e291cffc762",
    );

    /* PHP 7.3 Release */
    $PHP_7_3_VERSION         = "7.3.13";
    $PHP_7_3_DATE            = "18 Dec 2019";
    $PHP_7_3_TAGS            = ['security']; // Set to ['security'] for security releases.
    $PHP_7_3_SHA256     = array(
        "tar.bz2"       => "5c7b89062814f3c3953d1518f63ed463fd452929e3a37110af4170c5d23267bc",
        "tar.gz"        => "9cf835416a3471d7e6615e9288e76813d55ffaf60e0aa9ce74884a7c228cb6dd",
        "tar.xz"        => "57ac55fe442d2da650abeb9e6fa161bd3a98ba6528c029f076f8bba43dd5c228",
    );

    /* PHP 7.2 Release */
    $PHP_7_2_VERSION         = "7.2.26";
    $PHP_7_2_DATE            = "18 Dec 2019";
    $PHP_7_2_TAGS            = ['security']; // Set to ['security'] for security releases.
    $PHP_7_2_SHA256     = array(
        "tar.bz2"       => "f36d86eecf57ff919d6f67b064e1f41993f62e3991ea4796038d8d99c74e847b",
        "tar.gz"        => "e97d0636478bb519cd955a0c17b7970cf173063a840a83fc4afb75c22bc1bf08",
        "tar.xz"        => "1dd3bc875e105f5c9d21fb4dc240670bd2c22037820ff03890f5ab883c88b78d",
    );

    return array(
        7 => array(
            $PHP_7_4_VERSION => array(
                "announcement" => true,
                "tags" => $PHP_7_4_TAGS,
                "date" => $PHP_7_4_DATE,
                "source" => array(
                    array(
                        "filename" => "php-$PHP_7_4_VERSION.tar.bz2",
                        "name"     => "PHP $PHP_7_4_VERSION (tar.bz2)",
                        "sha256"   => $PHP_7_4_SHA256["tar.bz2"],
                        "date"     => $PHP_7_4_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_4_VERSION.tar.gz",
                        "name"     => "PHP $PHP_7_4_VERSION (tar.gz)",
                        "sha256"   => $PHP_7_4_SHA256["tar.gz"],
                        "date"     => $PHP_7_4_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_4_VERSION.tar.xz",
                        "name"     => "PHP $PHP_7_4_VERSION (tar.xz)",
                        "sha256"   => $PHP_7_4_SHA256["tar.xz"],
                        "date"     => $PHP_7_4_DATE,
                    ),
                ),
            ),
            $PHP_7_3_VERSION => array(
                "announcement" => true,
                "tags" => $PHP_7_3_TAGS,
                "date" => $PHP_7_3_DATE,
                "source" => array(
                    array(
                        "filename" => "php-$PHP_7_3_VERSION.tar.bz2",
                        "name"     => "PHP $PHP_7_3_VERSION (tar.bz2)",
                        "sha256"   => $PHP_7_3_SHA256["tar.bz2"],
                        "date"     => $PHP_7_3_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_3_VERSION.tar.gz",
                        "name"     => "PHP $PHP_7_3_VERSION (tar.gz)",
                        "sha256"   => $PHP_7_3_SHA256["tar.gz"],
                        "date"     => $PHP_7_3_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_3_VERSION.tar.xz",
                        "name"     => "PHP $PHP_7_3_VERSION (tar.xz)",
                        "sha256"   => $PHP_7_3_SHA256["tar.xz"],
                        "date"     => $PHP_7_3_DATE,
                    ),
                ),
            ),
            $PHP_7_2_VERSION => array(
                "announcement" => true,
                "tags" => $PHP_7_2_TAGS,
                "date" => $PHP_7_2_DATE,
                "source" => array(
                    array(
                        "filename" => "php-$PHP_7_2_VERSION.tar.bz2",
                        "name"     => "PHP $PHP_7_2_VERSION (tar.bz2)",
                        "sha256"   => $PHP_7_2_SHA256["tar.bz2"],
                        "date"     => $PHP_7_2_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_2_VERSION.tar.gz",
                        "name"     => "PHP $PHP_7_2_VERSION (tar.gz)",
                        "sha256"   => $PHP_7_2_SHA256["tar.gz"],
                        "date"     => $PHP_7_2_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_2_VERSION.tar.xz",
                        "name"     => "PHP $PHP_7_2_VERSION (tar.xz)",
                        "sha256"   => $PHP_7_2_SHA256["tar.xz"],
                        "date"     => $PHP_7_2_DATE,
                    ),
                ),
            ),
        ),
    );
})();

// Get latest release version and info.
function release_get_latest() {
    global $RELEASES;

    $version = null;
    $current = null;
    foreach ($RELEASES as $versions) {
        foreach ($versions as $ver => $info) {
            if (version_compare($ver, $version) > 0) {
                $version = $ver;
                $current = $info;
            }
        }
    }

    return [ $version, $current ];
}
