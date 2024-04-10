import * as THREE from 'three';
import { OBJLoader } from 'three/addons/loaders/OBJLoader.js';
import { MTLLoader } from 'three/addons/loaders/MTLLoader.js';
import { FontLoader } from 'three/addons/loaders/FontLoader.js';
import {TextGeometry} from 'three/addons/geometries/TextGeometry.js'
import {GAME_TYPE} from "./gameTemplate.js";

const CAM_INDEX = {
    'MY': 0,
    'MID': 1,
    'YOU': 2
};
const CAM = [
    {'x': 0, 'y': 715, 'z': 425},
    {'x': -150, 'y': 800, 'z': 0},
    {'x': 0, 'y': 715, 'z': -425}
];

class PlayGameApp {
    constructor(container, gameType) {
        this._gameType = gameType;
        this._camPosition = CAM_INDEX.MY;
        this._container = container;
        this._player = 1;

        const renderer = new THREE.WebGLRenderer({ antialias: true });
        container.appendChild(renderer.domElement);

        const scene = new THREE.Scene();

        this._renderer = renderer;
        this._scene = scene;

        if (gameType === GAME_TYPE.LOCAL_TWO || gameType === GAME_TYPE.LOCAL_TOURNAMENT) {
            this._camPosition = CAM_INDEX.MID;
        }
        this._setupCamera();
        this._setupAmbientLight();
        this._setupLight(-10, 200, 0);
        this._setupTable();
        this._setupMyPaddle();
        this._setupYourPaddle();
        this._setupBall();
        this.setupScore();

        window.resize = this.resize.bind(this);
        this.resize();
        requestAnimationFrame(this.render.bind(this));
    }

    getPlayer() {
        return this._player;
    }

    setPlayer(player) {
        this._player = player;
    }

    dataRander(data) {
        if (this._player === 1) {
            this.setupScore(data.score[0], data.score[1]);
            this.renderBall(data.ball_coords[1], 470, -data.ball_coords[0]);

            this.renderMyPaddle(data.player1_coords[1], 470, 340);
            this.renderYourPaddle(data.player2_coords[1], 470, -340);
        } else {
            this.setupScore(data.score[1], data.score[0]);
            this.renderBall(data.ball_coords[1], 470, data.ball_coords[0]);

            this.renderMyPaddle(data.player2_coords[1], 470, 340);
            this.renderYourPaddle(data.player1_coords[1], 470, -340);
        }
    }

    _setupCamera() {
        const width = this._container.clientWidth;
        const height = this._container.clientHeight;
        const camera = new THREE.PerspectiveCamera(75, width / height, 0.1, 10000);
        camera.position.set(CAM[this._camPosition].x, CAM[this._camPosition].y, CAM[this._camPosition].z);

        this._camera = camera;
        this._setLookCamera();
    }

    _setLookCamera() {
        if (this._camPosition === CAM_INDEX.MID) {
            this._camera.lookAt(50, 120, 0);
        } else {
            this._camera.lookAt(0, 120, 0);
        }
    }

    toggleCamera() {
        this._camPosition = (this._camPosition + 1) % CAM.length;
        this.setCamera(CAM[this._camPosition]);
    }

    setCamera(camPosition) {
        if (camPosition !== undefined) {
            this._camera.position.set(camPosition.x, camPosition.y, camPosition.z);
            this._setLookCamera();
        }
    }

    _setupAmbientLight() {
        const ambientLight = new THREE.AmbientLight(0xffffff, 0.5);
        this._scene.add(ambientLight);
    }

    _setupLight(x, y, z) {
        const color = 0xffffff;
        const intensity = 1;
        const light = new THREE.DirectionalLight(color, intensity);
        light.position.set(x, y, z);
        this._scene.add(light);
    }

    _setupTable() {
        const mtlLoader = new MTLLoader();
        mtlLoader.load(
            'src/assets/table.mtl',
            (materlials) => {
                materlials.preload();
                const objLoader = new OBJLoader();
                objLoader.setMaterials(materlials);
                objLoader.load(
                    'src/assets/table.obj',
                    (obj) => {
                        this._scene.add(obj);
                    },
                    (xhr) => {
                        // console.log((xhr.loaded / xhr.total * 100) + '% OBJ loaded');
                    },
                    (err) => console.error('Error:', err)
                );
            },
            (xhr) => {
                // console.log((xhr.loaded / xhr.total * 100) + '% MTL loaded');
            },
            (err) => console.error('Error:', err)
        );
    }

    renderCounter(counter) {
        if (counter !== undefined && (0 < counter && counter < 6)) {
            const loader = new FontLoader();
            loader.load('src/assets/Poetsen_One_Regular.json', font => {
                if (this._counter !== undefined) this._scene.remove(this._counter);

                const counterGeometry = new TextGeometry(`${counter}`, {
                    font: font,
                    size: 60,
                    height: 50,
                    curveSegments: 12,
                    bevelEnabled: false
                });
                const counterMaterial = new THREE.MeshPhongMaterial({color: 0xAE70FF});
                const counterMesh = new THREE.Mesh(counterGeometry, counterMaterial);

                counterMesh.position.set(-30, 520, 0);

                this._scene.add(counterMesh);
                this._counter = counterMesh;
            });
        } else {
            if (this._counter !== undefined) this._scene.remove(this._counter);
        }
    }

    setupScore(my, your) {
        let myScoreText = 0;
        let yourScoreText = 0;
        if (my !== undefined) myScoreText = my;
        if (your !== undefined) yourScoreText = your;
        const loader = new FontLoader();
        loader.load('src/assets/Poetsen_One_Regular.json', (font) => {

            if (this._yourScore !== undefined) this._scene.remove(this._yourScore);
            if (this._myScore !== undefined) this._scene.remove(this._myScore);

            const yourGeometry = new TextGeometry(`${yourScoreText}`, {
                font: font,
                size: 80,
                height: 1,
                curveSegments: 12,
                bevelEnabled: false
            });
            const yourMaterial = new THREE.MeshPhongMaterial({color: 0xAE70FF});
            const yourScore = new THREE.Mesh(yourGeometry, yourMaterial);

            yourScore.position.set(140, 450, -85);
            yourScore.rotation.set(-(Math.PI / 2), 0, -(Math.PI / 2));

            this._scene.add(yourScore);
            this._yourScore = yourScore;

            const myGeometry = new TextGeometry(`${myScoreText}`, {
                font: font,
                size: 80,
                height: 1,
                curveSegments: 12,
                bevelEnabled: false
            });
            const myMaterial = new THREE.MeshPhongMaterial({color: 0xAE70FF});
            const myScore = new THREE.Mesh(myGeometry, myMaterial);

            myScore.position.set(140, 450, 15);
            myScore.rotation.set(-(Math.PI / 2), 0, -(Math.PI / 2));

            this._scene.add(myScore);
            this._myScore = myScore;
        });
    }

    _setupMyPaddle() {
        const geometry = new THREE.BoxGeometry(60, 25, 20);
        const material = new THREE.MeshPhongMaterial({color: 0x351361});

        const paddle = new THREE.Mesh(geometry, material);

        paddle.position.set(0, 470, 340);

        this._scene.add(paddle);
        this._myPaddle = paddle;
    }

    _setupYourPaddle() {
        const geometry = new THREE.BoxGeometry(60, 25, 20);
        const material = new THREE.MeshPhongMaterial({color: 0x351361});

        const paddle = new THREE.Mesh(geometry, material);

        paddle.position.set(0, 470, -340);

        this._scene.add(paddle);
        this._yourPaddle = paddle;
    }

    _setupBall() {
        const geometry = new THREE.BoxGeometry(25, 25, 25);
        const material = new THREE.MeshPhongMaterial({color: 0xfff385});

        const ball = new THREE.Mesh(geometry, material);

        ball.position.set(0, 470, 0);

        this._scene.add(ball);
        this._ball = ball;
    }

    resize() {
        const width = this._container.clientWidth;
        const height = this._container.clientHeight;

        this._camera.aspect = width / height;
        this._camera.updateProjectionMatrix();

        this._renderer.setSize(width, height);
    }

    render() {
        this._renderer.render(this._scene, this._camera);
        this._animationFrame = requestAnimationFrame(this.render.bind(this));
    }

    cancelRender() {
        cancelAnimationFrame(this._animationFrame);
    }

    renderBall(x, y, z) {
        if (x !== undefined) this._ball.position.x = x;
        if (y !== undefined) this._ball.position.y = y;
        if (z !== undefined) this._ball.position.z = z;
    }

    renderMyPaddle(x, y, z) {
        if (x !== undefined) this._myPaddle.position.x = x;
        if (y !== undefined) this._myPaddle.position.y = y;
        if (z !== undefined) this._myPaddle.position.z = z;
    }

    renderYourPaddle(x, y, z) {
        if (x !== undefined) this._yourPaddle.position.x = x;
        if (y !== undefined) this._yourPaddle.position.y = y;
        if (z !== undefined) this._yourPaddle.position.z = z;
    }
}

export default PlayGameApp;